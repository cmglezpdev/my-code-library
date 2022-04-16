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
const int maxn = 3e5 + 1;
const int MOD = 1e9 + 9;
const ll inf = 1e10;
const db pi = acos(-1);
const db eps = 1e-9;

ll num[maxn];
struct lzy {
    
    ll b = 0, d = 0;

} lazy[4 * maxn];
ll st[4 * maxn];

ll at(ll b, ll d, ll n) {
    return b + (n - 1LL) * d;
}

ll sum(ll b, ll d, int l, int r) {
    ll x = at(b, d, 1);
    ll y = at(b, d, r - l + 1);
    ll n = (r - l + 1);
    return n * (x + y) / 2LL;
}

void pushdown(int node, int l, int r) {
    if( lazy[node].b == 0 && lazy[node].d == 0 ) return;
    st[node] += sum(lazy[node].b, lazy[node].d, l, r);

    if(l != r) {
        int mid = (l + r) >> 1;
        int ls = node << 1, rs = ls | 1;
        lazy[ls].b += lazy[node].b;
        lazy[ls].d += lazy[node].d;
        
        lazy[rs].b += at(lazy[node].b, lazy[node].d, mid + 2 - l);
        lazy[rs].d += lazy[node].d;
    }
    lazy[node].d = lazy[node].b = 0;
}

ll query_st(int node, int l, int r, int lq, int rq) {
    pushdown(node, l, r);
    if( lq > r || rq < l) return 0;
    if( lq <= l && rq >= r )
        return st[node];

    int ls = node << 1, rs = ls | 1;
    int mid = (l + r) >> 1;
    
    return query_st(ls, l, mid, lq, rq) + query_st(rs, mid + 1, r, lq, rq);
}

void update_st(int node, int l, int r, int lu, int ru, ll v) {
    pushdown(node, l, r);
    if(lu > r || ru < l) return;
    if(lu <= l && ru >= r) {
        lazy[node].b = at(v, v, l - lu + 1);    
        lazy[node].d = v;
        pushdown(node, l, r);
        return;
    }

    int ls = node << 1, rs = ls | 1;
    int mid = (l + r) >> 1;

    update_st(ls, l, mid, lu, ru, v);
    update_st(rs, mid + 1, r, lu, ru, v);

    st[node] = st[ls] + st[rs];
}

int main(){

    FAST

    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) 
        cin >> num[i];

    long long ans = 0;
    for(int i = n; i >= 1; i --) {

        ll v = query_st(1, 1, n, i, i);
        if( v >= num[i] ) continue;

        int l = (i - k + 1 >= 1) ? i - k + 1 : 1;
        int r = l + k - 1;
        ll vi = (ll)(i - l + 1);

        ll x = (num[i] - v) / vi;
        x += ( x * vi >= (num[i] - v) ) ? 0 : 1;
        ans += x;
        update_st(1, 1, n, l, r, x);
    }


    cout << ans;

}