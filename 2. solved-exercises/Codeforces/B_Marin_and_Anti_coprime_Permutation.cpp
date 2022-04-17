#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 1;
typedef long long ll;
ll MOD = 998244353LL;

ll fact[maxn];

int main() {


    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fact[1] = 1LL;
    for(int i = 2; i < maxn; i ++) {
        fact[i] = ( fact[i - 1] * (i * 1LL) ) % MOD;
    }



    int test; cin >> test;

    while(test --) {

        int n; cin >> n;

        if(n%2 != 0) {
            cout << "0\n"; 
            continue;
        }

        cout << (fact[n / 2] * fact[n / 2]) % MOD << '\n';

    }


}