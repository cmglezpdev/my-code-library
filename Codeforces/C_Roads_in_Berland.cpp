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
const int maxn = 301;
const int MOD = 1e9 + 9;
const ll inf = 1e10;
const db pi = acos(-1);
const db eps = 1e-9;

ll D[maxn][maxn];
ll dp[maxn][maxn];

int main(){

    FAST

    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            cin >> D[i][j];   
        }
    }


    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n;j ++) {
            for(int k = 1; k <= n; k ++) {
                dp[i][j] = min( D[i][j], D[i][k] + D[k][j] );
            }
        }
    }

    int m; cin >> m;
    while( m -- ) {
        int x, y, z;
        cin >> x >> y >> z;
        ll sol = 0;
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                dp[i][j] = min(dp[i][j], dp[i][x] + z + dp[y][j]);
                dp[i][j] = min(dp[i][j], dp[i][y] + z + dp[x][j]);
                if( j > i ) sol += dp[i][j];
            }
        }
        cout << sol << " ";
    }

}