#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sum(ll x, ll y) {
    ll a = y * (y + 1LL) / 2LL;
    ll b = (x - 1LL)*x / 2LL;

    return a - b;
}

int main() {

    int n; cin >> n;

    for(int i = 1; i <= n; i ++) {
        ll x = sum(1LL, i - 1LL);
        ll y = sum(i + 1LL, n);

        if( x == y ) {
            cout << i << '\n';
            return 0;
        }
    }

}