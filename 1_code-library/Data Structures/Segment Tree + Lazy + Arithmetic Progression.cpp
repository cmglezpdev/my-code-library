#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 1;
#define ll long long

ll arr[maxn];


struct lzy {
    // base, increasing 
    ll b;
    ll d;
} lazy[4 * maxn];
ll st[4 * maxn];

// Arithmetic Progression:
// b, b + d, b + 2d, ..... , b + nd, ....
ll nth(ll b, ll d, ll n) {
    return b + (n - 1) * d;
}

ll sum(ll b, ll d, int l, int r) {
    ll x = nth(b, d, 1);
    ll y = nth(b, d, r - l + 1);
    int n = r - l + 1;
    return n * (x + y) / 2LL;
}

void build_st(int node, int l, int r) {

    if( l == r ) {
        st[node] = arr[l];
        return;
    }
    int ls = 2 * node, rs = ls + 1;
    int mid= (l + r) >> 1;
    build_st(ls, l, mid);
    build_st(rs, mid + 1, r);

    st[node] = st[ls] + st[rs];
}

void pushdown(int node, int l, int r) {
    if( lazy[node].b == 0  && lazy[node].d == 0 ) return;
    st[node] += sum( lazy[node].b, lazy[node].d, l , r);

    if(l != r) {
        int mid = (l + r) >> 1;
        int ls = 2 * node, rs = ls + 1;

        lazy[ls].b += lazy[node].b;
        lazy[ls].d += lazy[node].d;

        lazy[rs].b += nth(lazy[node].b, lazy[node].d, mid - l + 2);
        lazy[rs].d += lazy[node].d;
    }
    lazy[node].d = lazy[node].b = 0;
}

ll query_st(int node, int l, int r, int lq, int rq) {
    pushdown(node, l, r);
    if(lq > r || rq < l) return 0;
    if( lq <= l && rq >= r ) return st[node];

    int mid = (l + r) >> 1;
    int ls = 2 * node, rs = ls + 1;

    return query_st(ls, l, mid, lq, rq) + query_st(rs, mid + 1, r, lq, rq);
}

void update_st(int node, int l, int r, int lu, int ru) {
    pushdown(node, l, r);
    if( lu > r || ru < l ) return;
    if( lu <= l && ru >= r ) {
        lazy[node].b = (ll)(l - lu + 1);
        lazy[node].d = 1LL;
        pushdown(node, l, r);
        return;
    }

    int mid = (l + r) >> 1;
    int ls = 2 * node, rs = ls + 1;

    update_st(ls, l, mid, lu, ru);
    update_st(rs, mid + 1, r, lu, ru);

    st[node] = st[ls] + st[rs];
}




int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // freopen("test_input.txt", "r", stdin);
    // freopen("sol.txt", "w", stdout);

    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) cin >> arr[i];

    build_st(1, 1, n);
    while(q --) {
        int op, l ,r;
        cin >> op >> l >> r;
        if( op == 1 ) 
            update_st(1, 1, n, l, r);
        else
            cout << query_st(1, 1, n, l, r) << '\n';
    }
}

// https://cses.fi/problemset/task/1736