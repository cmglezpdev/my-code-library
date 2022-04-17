#include<bits/stdc++.h>

using namespace std;

#define int long long
const int maxn = 100005;
int dp[maxn], sol[maxn], sub[maxn], n;
bool seen[maxn];
vector<int> g[maxn];

void dfs(int node){
    seen[node] = true;
    sub[node] = 1;
    dp[node] = 0;
    for(auto newn : g[node]){
        if( !seen[newn] ){
            dfs(newn);
            sub[node] += sub[newn];
            dp[node] += dp[newn] + sub[newn];
        }
    }
}

void dfs2(int node){
    seen[node] = true;
    for(auto newn : g[node]){
        if(seen[newn]) continue;
        sol[newn] = sol[node] + (n-sub[newn]) - sub[newn];
        dfs2(newn);
    }
}


main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i < n; i ++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    fill(seen, seen + maxn, 0);
    sol[1] = dp[1];
    dfs2(1);

    for(int i = 1; i <= n;i ++)
        cout << sol[i] << '\n';
}