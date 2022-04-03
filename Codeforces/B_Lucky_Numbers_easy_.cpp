#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll sol = 1e15 * 1LL;

void Solve( ll number, int len, int cant4, int cant7, ll n ) {

    if( cant4 == cant7 && number >= n ) {
        if( abs(n - number) < abs(n - sol) )
            sol = number;
    }

    if(len == 10) return;

    Solve( number * 10LL + 4LL, len + 1, cant4 + 1, cant7, n );
    Solve( number * 10LL + 7LL, len + 1, cant4, cant7 + 1, n );

}



int main() {

    ll n; cin >> n;
    Solve(0, 0, 0, 0, n);

    cout << sol << '\n';
}