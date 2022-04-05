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
const int maxn = 1e4 + 1;
const int MOD = 1e9 + 7;
const ll inf = 1e10;
const db pi = acos(-1);
const db eps = 1e-9;

char board[maxn][maxn];
int dp[maxn][maxn];

int main(){

    int h, w;
    cin >> h >> w;

    for(int i = 1; i <= h; i ++) {
        for(int j = 1; j <= w; j ++)
            cin >> board[i][j];
    }

    dp[1][1] = 1;
    for(int i = 1; i <= h; i ++) {
        for(int j = 1; j <= w; j ++) {
            if(i == j && i == 1) continue;
            if( board[i][j] == '#' ) continue;
            dp[i][j] = (long long)( dp[i - 1][j] + dp[i][j - 1] ) % MOD;
        }
    }

    cout << dp[h][w] << '\n';
}