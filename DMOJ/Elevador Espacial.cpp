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
const int maxn = 401;
const int maxa = 11;
const int MOD = 1e9 + 9;
const ll inf = 1e10;
const db pi = acos(-1);
const db eps = 1e-9;

pair<int, pair<int, int>> v[maxn];
int dp[maxn][maxa];

int main(){

    FAST

    int n; cin >> n;
    for(int i = 1; i <= n; i ++){
        int h, a, c;
        cin >> h >> a >> c;
        v[i] = mp(a, mp(h, c));
    }

    sort(v + 1, v + 1 + n);

    for(int i = 1; i <= v[1].s.s; i ++) {
        int h = v[1].s.f, a = v[1].f;
        if( i * h <= a ) 
            dp[1][i] = i * h;
    }

    for(int i = 2; i <= n; i ++) {
        int a = v[i].f;
        int h = v[i].s.f;
        int c = v[i].s.s;
        
        int b = v[i - 1].s.s;
        for(int k = 1; k <= b; k ++) {
            for(int j = 1; j <= c; j ++) {
                if( dp[i - 1][k] + j*h <= a )
                    dp[i][j] = max( dp[i][j], dp[i - 1][k] + j*h );
            }
        }
    }


    int ans = 0;
    int b = v[n].s.s;
    for(int i = 1; i <= b; i ++)
        ans = max(ans, dp[n][i]);

    cout << ans;
}