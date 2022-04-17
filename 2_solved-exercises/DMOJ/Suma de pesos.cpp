#include<bits/stdc++.h>

using namespace std;

const int maxn = 100005;
typedef long long ll;
#define f first
#define s second
ll sol[maxn], dp[maxn];
int subt[maxn];
bool mark[maxn], color[maxn];
vector<pair<int, ll> > g[maxn];

void dfs(int u){
    mark[u] = true;
    subt[u] = color[u];
    dp[u] = 0;
    for(auto i : g[u]){
        int v = i.f;
        ll c = i.s;
        if(mark[v]) continue;
        dfs(v);
        subt[u] += subt[v];
        dp[u] += dp[v] + (ll)c*subt[v];
    }
}

void dfs2(int u){
    mark[u] = true;
    for(auto i : g[u]){
        int v = i.f;
        int c = i.s;
        if(mark[v]) continue;
        sol[v] += sol[u] + (ll)c*(subt[1]-subt[v]) - (ll)c*subt[v];
        dfs2(v);
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> color[i];
    for(int i = 1; i < n; i ++){
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back(make_pair(v, (ll)c));
        g[v].push_back(make_pair(u, (ll)c));
    }
    dfs(1);
    fill(mark, mark + maxn, false);
    sol[1] = dp[1];
    dfs2(1);

    ll answer = 0;
    for(int i = 1; i <= n; i ++)
        if(!color[i]) answer += sol[i];
    cout << answer;


}