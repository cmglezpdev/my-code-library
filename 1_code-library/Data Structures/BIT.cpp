#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 1;
int bit[maxn];
int n;

void update(int x, int upd) {
    for( ; x <= n; x += (x&-x)) 
        bit[x] += upd;   
}

int query(int x) {
    int result = 0;
    for( ; x >= 1; x -= (x&-x) )
        result += bit[x];
    return result;
}   

int query(int l, int r) {
    return query(r) - query(l - 1);
}

int main(){

    cin >> n;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        update(i, x);
    }

    int q; cin >> q;
    while(q --) {
        int l, r;
        cin >> l>> r;
        cout << query(l, r) << '\n';
    }

}

/*
LINKS
1. https://codeforces.com/blog/entry/57292 --> Best explication
2. https://cp-algorithms.com/data_structures/fenwick.html
*/