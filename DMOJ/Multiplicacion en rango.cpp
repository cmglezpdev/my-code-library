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
const ll MOD = 1e9 + 9;
const ll inf = 1e9;
const double pi = acos(-1);
const db eps = 1e-9;

ll Mult(ll a, ll b, ll m) {
    if( a * b < m) return a * b;
    ll q = a * b / m;
    ll r = a * b - q * m;
    if(r < 0) r += m;
    return r;
}

ll Add(ll a, ll b, ll m){
    a += b;
    if( a >= m) 
        a -= m;
    return a;
} 


ll st[4*maxn];
ll lazy[4*maxn];

void build_st(int node, int l, int r) {
    if(l == r){
        st[node] = 1LL;
        lazy[node] = 1LL;
        return;
    }

    int mid = (l + r) / 2;
    int ls = 2 * node, rs = ls + 1;

    build_st(ls, l, mid);
    build_st(rs, mid + 1, r);

    st[node] = Add(st[ls], st[rs], MOD);
    lazy[node] = 1LL;
}

void propagate_st(int node, int l, int r) {
    if(lazy[node] == 1LL) return;

    st[node] = Mult(st[node], lazy[node], MOD);
    
    if(l != r) {
        int mid = (l + r) / 2;
        int ls = 2 * node, rs = ls + 1;

        lazy[ls] = Mult(lazy[ls], lazy[node], MOD);
        lazy[rs] = Mult(lazy[rs], lazy[node], MOD);
    }

    lazy[node] = 1LL;
}

void update_st(int node, int l, int r, int lu, int ru, ll k) {
     propagate_st(node, l, r);
    if( lu > r || ru < l )  return;
    if( lu <= l && ru >= r ) {
        lazy[node] = Mult(lazy[node], k, MOD);
        propagate_st(node, l, r);
        return;
    }
    
    int mid = (l + r) / 2;
    int ls = 2 * node, rs = ls + 1;

    update_st(ls, l, mid, lu, ru, k);
    update_st(rs, mid + 1, r, lu, ru, k);

    st[node] = Add(st[ls], st[rs], MOD);
}

ll query_st(int node, int l, int r, int lq, int rq) {
    propagate_st(node, l, r);
    if( lq > r || rq < l ) return 0;
    if( lq <= l && rq >= r ) {
        return st[node] % MOD;
    }
    int mid = (l + r) / 2;
    int ls = 2 * node, rs = ls + 1;

    return Add(query_st(ls, l, mid, lq, rq), query_st(rs, mid + 1, r, lq, rq), MOD);
}


int main(){

    FAST

    int n, m;
    cin >> n >> m;

    build_st(1, 1, n);

    while (m --)
    {
        int op, l, r;
        cin >> op >> l >> r;

        if( op == 0) {
            ll k;
            cin >> k;
            update_st(1, 1, n, l, r, k);
        }
        if(op == 1) {
            cout << query_st(1, 1, n, l, r) << '\n';
        }
    }
    
}