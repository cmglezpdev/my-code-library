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

int st[4 * maxn];
int a[maxn];

void build_st(int node, int l, int r) {
    if( l == r) {
        st[node] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    int ls = node << 1, rs = ls | 1;
    build_st(ls, l, mid);
    build_st(rs, mid + 1, r);

    st[node] = min(st[ls], st[rs]);
}

int query_st(int node, int l, int r, int lq, int rq) {
    if( lq > r || rq < l ) return (1<<30);
    if( lq <= l && rq >= r ) return st[node];

    int mid = (l + r) >> 1;
    int ls = node << 1, rs = ls | 1;
    return min(query_st(ls, l, mid, lq, rq), query_st(rs, mid + 1, r, lq, rq));
}

int main(){

    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    build_st(1, 1, n);

    while (q --) {
        int l, r;
        cin >> l >> r;
        cout << query_st(1, 1, n, l, r) << '\n';
    }
    

}