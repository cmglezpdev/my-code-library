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
const ll inf = -1e10;
const db pi = acos(-1);
const db eps = 1e-9;

ll a[maxn];
ll dp[maxn][2];

int main(){

    int n; cin  >> n;
    ll sum = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if( a[i] > 0 ) sum += a[i];
    }

    if( sum % 2 != 0 ) {
        cout << sum;
        return 0;
    }
    ll ans = inf;
    for(int i = 1; i <= n; i ++) {
        if( a[i]%2 != 0 ) {
            if( a[i] < 0 )
                ans = max(ans, sum + a[i]);
            else 
                ans = max(ans, sum - a[i]);
        }
    }

    cout << ans;

}