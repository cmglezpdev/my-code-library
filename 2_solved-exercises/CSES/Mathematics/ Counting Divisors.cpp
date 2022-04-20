#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 1e3 + 1;
vector<ll> p;
bool isp[maxn];

void Sieve() {
    
    fill(isp, isp + maxn, true);
    isp[0] = isp[1] = false;

    for(int i = 2; i < maxn; i ++) {
        if(isp[i]) {
            p.push_back(i);
            for(int j = i * i; j < maxn; j += i)    
                isp[j] = false;
        }
    }

}

int CountDivisors(ll n) {
    ll ans = 1;
    for(auto &i: p) {
        if( i * i > n ) break;
        if( n%i == 0 ) {
            ll c = 1;
            while(n%i == 0) {
                n /= i;
                c ++;
            }
            ans *= c;
        }
    }
    if(n > 1) ans *= 2LL;
    return ans;
}

int main(){

    Sieve();
    int tt; cin >> tt;
    while(tt --) {
        int n; cin >> n;
        cout << CountDivisors(n) << '\n';
    }
}