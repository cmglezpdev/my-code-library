#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 2e5 + 1;
vector<int> g[maxn];


int dfs(int u) {

    if( g[u].size() == 0 )
        return 1;

    int ans = 0;
    for(auto &v : g[u]) {
        ans += dfs(v);
    }
    return ans;
}

vector<int> sol;

void dfs2(int u) {

    sol.push_back(u);
    if( g[u].size() == 0 ) {
        cout << sol.size() << '\n';
        for(auto &v : sol) {
            cout << v << ' ';
        }
        cout << '\n';
        return;
    }

    dfs2(g[u][0]);
    for(int i = 1; i < g[u].size(); i ++) {
        sol.clear();
        dfs2(g[u][i]);
    }

}


void clear() {
    for(int i = 0; i < maxn; i ++) {
        g[i].clear();
    }

    sol.clear();
}

int main(){

    // freopen("data.txt", "w", stdout);

    int tt; cin >> tt;
    while(tt --) {
       clear();

        int n; cin >> n;
        int root = 0;
        for(int i = 1; i <= n; i ++) {
            int p; cin >> p;
            if(p == i) {
                root = i;
                continue;
            }
            g[p].push_back(i);
        }

        int len = dfs(root);
        cout << len << '\n';
        dfs2(root);
        cout << '\n';
    }
}