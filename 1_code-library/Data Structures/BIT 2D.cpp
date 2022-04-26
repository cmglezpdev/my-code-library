#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 1;
int bit[maxn][maxn];
int n;

void update(int x, int y, int upd) {
    for( int i = x; i <= n; i += (i&-i)) 
        for( int j = y; j <= n; j += (j&-j))
            bit[i][j] += upd;   
}

int query(int x, int y) {
    int result = 0;
    for( int i = x; i >= 1; i -= (i&-i) )
        for(int j = y; j >= 1; j -= (j&-j))
            result += bit[i][j];
    return result;
}   

int query(int a, int b, int c, int d) {
    return query(c, d) - query(a - 1, d) - query(c, b - 1) + query(a - 1, b - 1);
}

int main(){

    cin >> n;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            int x; cin >> x;
            update(i, j, x);
        }
    }

    int q; cin >> q;
    while(q --) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << query(a, b, c, d) << '\n';
    }

}

/*
LINKS
1. https://cp-algorithms.com/data_structures/fenwick.html
*/