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
const int maxn = 2e5 + 1;
const int MOD = 1e9 + 9;
const ll inf = 1e10;
const db pi = acos(-1);
const db eps = 1e-9;

ll a[maxn];

int main(){

    int tt; cin >> tt;
    while(tt -- ){
        int n; cin >> n;
        for(int i = 1; i <= n; i ++) cin >> a[i];

        sort(a + 1, a + n + 1);
        ll ans = a[1];
        ll acum = a[1];
        for(int i = 2; i <= n; i ++) {
            a[i] -= acum;
            ans = max(ans, a[i]);
            acum += a[i];
        }

        cout << ans << '\n';
    }

}