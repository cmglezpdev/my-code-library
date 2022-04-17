// FIXED: Esta mal

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
const int maxn = 1e5 + 1;
const int MOD = 1e9 + 9;
const ll inf = 1e10;
const db pi = acos(-1);
const db eps = 1e-9;

ll dp[maxn];
int cnt[maxn][3];
const int A = 0, B = 1, C = 2;
ll a[maxn], b[maxn], c[maxn];

ll max(ll x, ll y, ll z) {
    return max(x, max(y, z));
}

int main(){

    int n; cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> a[i] >> b[i] >> c[i];

    dp[1] = max(a[1], b[1], c[1]);
    if( dp[1] == a[1] ) cnt[1][A] ++;
    else 
    if( dp[1] == b[1] ) cnt[1][B] ++;
    else 
    if( dp[1] == c[1] ) cnt[1][C] ++;
    

    for(int i = 2; i <= n; i ++) {
        if( cnt[i - 1][A] ) dp[i] = max(dp[i - 1] + b[i], dp[i - 1] + c[i]);
        else
        if( cnt[i - 1][B] ) dp[i] = max(dp[i - 1] + a[i], dp[i - 1] + c[i]);      
        else
        if( cnt[i - 1][C] ) dp[i] = max(dp[i - 1] + a[i], dp[i - 1] + b[i]); 

        if( dp[i] == dp[i - 1] + a[i] ) cnt[i][A] ++;
        else 
        if( dp[i] == dp[i - 1] + b[i] ) cnt[i][B] ++;
        else 
        if( dp[i] == dp[i - 1] + c[i] ) cnt[i][C] ++;
    }

    cout << dp[n] << '\n';

}
