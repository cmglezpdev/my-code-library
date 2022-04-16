#include<bits/stdc++.h>

using namespace std;

const int maxn = 2 * 1e3 + 1;
int lv[maxn];
vector<int> tree[maxn];
vector<int> bosses;

int dfs(int node, int parent) {
    if(  parent == -1 )
        lv[node] = 1;
    else
        lv[node] = lv[parent] + 1;

    int maxLv = lv[node];

    for(auto v : tree[node]) {
        maxLv = max( maxLv, dfs(v, node) );
    }

    return maxLv;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        int emp; cin >> emp;
        if( emp == -1 ) {
            bosses.push_back(i);
            continue;
        }

        tree[emp].push_back(i);
    }

    int sol = 0;
    for( auto boss : bosses ) {
        sol = max(sol, dfs(boss, -1) );
    }

    cout << sol << '\n';
}