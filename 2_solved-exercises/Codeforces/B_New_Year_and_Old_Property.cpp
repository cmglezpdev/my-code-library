#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ll l, r;
    cin >> l >> r;

    int szl = floor(log2(l)) + 1;
    int szr = floor(log2(r)) + 1;
    
    int cant = 0;
    for(int i = szl; i <= szr; i ++) {
         ll n = (1LL << (i*1LL)) - 1LL;
        for(int j = 0; j < i - 1; j ++) {
            ll x = n&~(1LL<<j);
            if(x >= l && x <= r) 
                cant ++;
        }
    }

    cout << cant << '\n';
}