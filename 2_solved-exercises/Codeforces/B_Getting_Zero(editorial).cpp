#include<bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 32768LL;

int steps(ll n) {
    
    int ans = 20;
    for(int i = 0; i <= 15; i ++ ){
        for(int j = 0; j <= 15; j ++) {
            ll cntAdd = i;
            ll cntPow = (1LL<<j);
            if( (n + cntAdd) * cntPow % MOD == 0 )
                ans = min(ans, i + j);
        }
    }
    return ans;
}

int main() {

    int n; cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i ++) {
        cin >> v[i];
    }

    for(int i = 0; i < n; i ++) {
        cout << steps(v[i]) << ' ';
    }


}

