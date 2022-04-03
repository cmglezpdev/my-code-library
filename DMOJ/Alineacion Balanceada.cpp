#include <bits/stdc++.h>

using namespace std;

const int maxn = 200005;
#define two pair<int, int>
#define F first
#define S second

struct stree{
    int maxi;
    int mini;
}st[4*maxn];

int A[maxn];

void build_st(int node, int l, int r){
    if( l == r ){
        st[node].maxi = A[l];
        st[node].mini = A[l];
        return;
    }

    int mid = (l + r)/2;
    int ls = 2*node, rs = ls + 1;

    build_st(ls, l, mid);
    build_st(rs, mid+1, r);

    st[node].mini = min( st[ls].mini, st[rs].mini );
    st[node].maxi = max( st[ls].maxi, st[rs].maxi );
}

two query_st(int node, int l, int r, int lq, int rq){
    if( lq > r || rq < l )
        return two(0, 1e9);
    if( lq <= l && rq >= r )
        return two( st[node].maxi, st[node].mini );

    int ls = 2*node, rs = ls + 1;
    int mid = (l + r)/2;

    two a = query_st(ls, l, mid, lq, rq);
    two b = query_st(rs, mid+1, r, lq, rq);

    return two( max( a.F, b.F ), min( a.S, b.S ) );
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

   int n, m;
   cin >> n >> m;

    for(int i = 1; i <= n; i ++)
        cin >> A[i];

    build_st(1, 1, n);

   while( m -- ){
        int a, b;
        cin >> a >> b;
        two sol = query_st(1, 1, n, a, b);
        cout << sol.F - sol.S << '\n';
   }

}