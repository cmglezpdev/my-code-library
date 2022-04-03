#include<bits/stdc++.h>

using namespace std;

const int maxn = 3005;
#define pb push_back
bool seen[maxn], mk[maxn];
vector<int>g[maxn];
int k;

void clean(){
    fill(mk, mk + maxn, 0);
}

void dfs( int node ){
    k ++;
    mk[node] = true;
    for( auto newn : g[node] ){
        if( seen[newn] ) continue;
        if( mk[newn] ) continue;
        dfs(newn);
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    int tot = n;
    for(int i = 0; i < n; i ++ ){
        int a; cin >> a;
        dfs(a);
        if( k == tot ) cout << "YES\n";
        else cout << "NO\n";
        seen[a] = true;
        clean();
        tot --, k = 0;
    }

}