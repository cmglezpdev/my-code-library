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
const int maxn = 1e6 + 1;
const ll mod = 1LL * 1e9 + 9;
const ll B = 31LL;
const ll inf = 1e10;
const db pi = acos(-1);
const db eps = 1e-9;


ll Pow[maxn];
ll H[maxn];
ll Hr[maxn];

void build( string &w ) {
    Pow[0] = 1LL;
    for(int i = 1; i < maxn; i ++) {
        Pow[i] = (Pow[i - 1]  * B) % mod;
    }

    int n = w.size() - 1;
    for(int i = 1, j = n; i <= n; i ++, j --) {
        H[i] = ((H[i - 1] * B)% mod + w[i])%mod;
        Hr[i] = ((Hr[i - 1] * B)% mod + w[j])%mod;
    }
}

ll getHashd(int l, int r) {
    if(l == r) return H[r]%mod;
    ll result = H[r] - (H[l - 1] * Pow[r - l + 1])%mod;
    if( result < 0 ) result += mod;
    return result;
}

ll getHashr(int l, int r) {
    if(l == r) return Hr[r]%mod;
    ll result = Hr[r] - (Hr[l - 1] * Pow[r - l + 1])%mod;
    if( result < 0 ) result += mod;
    return result;
}

int main(){

    string w; cin >> w;
    w = ' ' + w;
    int n = w.size() - 1;
    build(w);

    int ans = n - 1;
    for(int i = n; i >= 1; i --) {
        ll hasha = getHashd(i, n);
        ll hashb = getHashr(1, n - i + 1);
        if( hasha == hashb ) ans = min( ans, i - 1 );
    }

    cout << ans;
}