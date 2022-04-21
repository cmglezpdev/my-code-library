#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 1e5 + 1;
const ll mod = 1LL * 1e9 + 7;
struct mt {
    ll v[2][2];

    mt(ll x) {
        for(int i = 0; i < 2; i ++) {
            for(int j = 0; j < 2; j ++)
                v[i][j] = 0;
            v[i][i] = x;
        }
    }

    ll *operator [](int row) {
        return v[row];
    }
    const ll *operator [](int row) const {
        return v[row];
    }
};

const mt operator *(const mt &ls, const mt &rs) {
    mt result(0);
    for(int i = 0; i < 2; i ++) {
        for(int j = 0; j < 2; j ++) {
            for(int k = 0; k < 2; k ++) {
                result[i][j] += (ls[i][k] * rs[k][j])%mod;
                if( result[i][j] >= mod ) result[i][j] -= mod;
            }
        }
    }
    return result;
}

mt Pow(mt m, ll n) {
    mt p = mt(1);
    while(n) {
        if( n&1 ) p = p * m;
        m = m * m;
        n >>= 1;
    }
    return p;
}

ll fibo(ll n) {
    if( n == 0 ) return 0LL;
    if( n == 1 ) return 1LL;

    vector<ll> v = {0LL, 1LL};

    mt M(0);
    M[0][0] = 0LL; M[0][1] = 1LL;
    M[1][0] = 1LL; M[1][1] = 1LL;


    auto P = Pow(M, n);
    ll fib = 0;
    for(int i = 0; i < 2; i ++) {
        fib += (v[i] * P[i][0])%mod;
        if(fib >= mod) fib -= mod;
    }
    return fib;
}

int main(){

    ll n; cin >> n;
    cout << fibo(n);

}