#include<bits/stdc++.h>

using namespace std;

const int maxn = 100005;
const int LG = 20;
int LCA[maxn][LG];
int MX[maxn][LG];
int MI[maxn][LG];
int lv[maxn];
#define two pair<int, int>
#define F first
#define S second
vector<two> g[maxn];

void build(){
    queue<int>q;
    q.push(1);
    lv[1] = 1;

    while( !q.empty() ){
        int node = q.front();
        q.pop();

        for( auto i : g[node] ){
            int newn = i.F;
            int cost = i.S;
            if( !lv[newn] ){
                q.push(newn);
                lv[newn] = lv[node] + 1;
                LCA[newn][0] = node;
                MX[newn][0] = MI[newn][0] = cost;

                int lg = log2(lv[newn]);
                for(int k = 1; k <= lg; k ++){
                    if( LCA[newn][k - 1] ){
                        LCA[newn][k] = LCA[ LCA[newn][k - 1] ][k - 1];
                        MI[newn][k] = min( MI[newn][k - 1], MI[ LCA[newn][k - 1] ][k - 1] );
                        MX[newn][k] = max( MX[newn][k - 1], MX[ LCA[newn][k - 1] ][k - 1] );
                    }
                }
            }
        }
    }

}

two lca(int a, int b){
    if( lv[a] < lv[b] )
        swap(a, b);

    int mini = 1e9,
    maxi = 0;
    int lg = log2(lv[a]);
    for(int i = lg; i >= 0; i --){
        if( (lv[a] - (1ll<<i)) >= lv[b] && LCA[a][i] ){
            mini = min( mini, MI[a][i] );
            maxi = max( maxi, MX[a][i] );
            a = LCA[a][i];
        }
    }

    if( a == b ) return two(mini, maxi);

    for(int i = lg; i >= 0; i --){
        if( LCA[a][i] != LCA[b][i] && LCA[a][i] ){
            mini = min( mini, min( MI[a][i], MI[b][i] ) );
            maxi = max( maxi, max( MX[a][i], MX[b][i] ) );
            a = LCA[a][i], b = LCA[b][i];
        }
    }

    mini = min( mini, min( MI[a][0], MI[b][0] ) );
    maxi = max( maxi, max( MX[a][0], MX[b][0] ) );

    return {mini, maxi};
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
     cin >> n;
     for(int i = 1; i < n; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back( two(b, c) );
        g[b].push_back( two(a, c) );
    }
    build();
        int q; cin >> q;
        while( q -- ){
            int a, b;
            cin >> a >> b;
            two sol = lca(a, b);
            cout << sol.F << ' ' << sol.S << '\n';

        }

}