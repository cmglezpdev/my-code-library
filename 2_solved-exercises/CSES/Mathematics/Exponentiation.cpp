#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 1e5 + 1;
const ll mod = 1e9 + 7;

ll mult(ll a, ll b) {
    if( a * b < mod ) return a * b;
    ll q = a * b / mod;
    ll r = a * b - q * mod;
    return r;
}

ll Pow(ll b, ll e) {
    if( e == 0 || b == 1LL ) return 1;
    if( e == 1) return b%mod;

    ll tmp = Pow(b, e / 2LL);
    tmp = mult(tmp, tmp);
    return mult( tmp, Pow(b, e%2LL) );
}

int main(){

    int tt; cin >> tt;
    while(tt --) {
        ll a, b;
        cin >> a >> b;
        cout << Pow(a, b)%mod << '\n';
    }
    
}