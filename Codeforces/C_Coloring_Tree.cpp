#include<bits/stdc++.h>
//For ordered_set
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
#define ldb long double
#define db double
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define mp make_pair
#define pb push_back
#define pf push_front
#define f first
#define s second
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int maxn = 101;
const int MOD = 1e9 + 9;
const ll inf = (1e18);
const db pi = acos(-1);
const db eps = 1e-9;

int color[maxn];
ll cost[maxn][maxn];
ll dp[maxn][maxn][maxn];

int main(){

    FAST

    int N, M, K;
    cin >> N >> M >> K;

    for(int i = 1; i <= N; i ++) cin >> color[i];
    for(int i = 1; i <= N; i ++) {
        for(int j = 1; j <= M; j ++) {
            cin >> cost[i][j];
        }
    }

    for(int i = 0; i <= N; i ++) {
        for(int j = 0; j <= K; j ++) {
            for(int k = 0; k <= M; k ++) {
                dp[i][j][k] = inf;
            }
        }
    }

    if( color[1] == 0 ) {
        for(int i = 1; i <= M; i ++)
            dp[1][1][i] = cost[1][i];
    }
    else    
        dp[1][1][ color[1] ] = 0;


    for(int i = 2; i <= N; i ++) {
        for(int j = 1; j <= K; j ++) {
            if( color[i] == 0 ) {
                for(int k = 1; k <= M; k ++) {
                    dp[i][j][k] = min( dp[i][j][k], dp[i - 1][j][k] + cost[i][k]);
                    for(int h = 1; h <= M; h ++) {
                        if( h != k ) dp[i][j][k] = min( dp[i][j][k], dp[i - 1][j - 1][h] + cost[i][k] ); 
                    }
                }
            } else {
                for(int k = 1; k <= M; k ++) {
                    if( color[i] == k ) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                    else dp[i][j][ color[i] ] = min(dp[i][j][ color[i] ], dp[i - 1][j - 1][k]);
                }               
            }


        }
    }
    ll ans = inf;
    for(int i = 1; i <= M; i ++) {
        ans = min(ans, dp[N][K][i]);
    }
    if(ans >= inf) ans = -1;
    cout << ans;
}