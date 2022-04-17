#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;
const int oo = 1e9;
int st[4*maxn];
int A[maxn];

void build_st(int node, int l, int r){
    if( l == r ){
        st[node] = A[l];
        return;
    }
    int ls = 2*node, rs = ls + 1;
    int mid = (l + r)/2;

    build_st(ls, l, mid);
    build_st(rs, mid+1, r);

    st[node] = max( st[ls], st[rs] );
}

int max_st(int node, int l, int r, int lq, int rq){
    if( lq > r || rq < l ) return 0;
    if( lq <= l && rq >= r ) return st[node];

    int ls = 2*node, rs = ls + 1;
    int mid = (l + r)/2;

    return max( max_st(ls, l, mid, lq, rq), max_st(rs, mid+1, r, lq, rq) );
}

int query_st(int node, int l, int r, int lq, int rq, int qs){
    if( l == r ) return l;
    if( lq > r || rq < l ) return oo;

    int ls = 2*node, rs = ls + 1;
    int mid = (l + r)/2;

    int maxi = max_st(ls, l, mid, lq, rq);
    if( maxi >= qs ){
        int ans = query_st( ls, l, mid, lq, rq , qs);
        if( ans != oo ) return ans;
    }else{
        maxi = max_st( rs, mid+1, r, lq, rq );
        if( maxi >= qs ){
            int ans = query_st( rs, mid+1, r, lq, rq, qs );
            if( ans != oo ) return ans;
        }
    }
    return oo;
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> A[i];

    build_st( 1, 1, n );

    int q; cin >> q;
    while( q -- ){
        int x, l, r;
        cin >> x >> l >> r;
        int answer = query_st( 1, 1, n, l, r, x );
        ( answer == oo ) ? cout << "-1\n" : cout << answer << '\n';

    }


}