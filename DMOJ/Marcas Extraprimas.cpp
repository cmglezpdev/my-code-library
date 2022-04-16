#include<bits/stdc++.h>
//For ordered_set
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
#define ldb long double
#define db double
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define mp make_pair
#define pb push_back
#define pf push_front
#define f first
#define s second
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int maxn = 1e5 + 1;
const int MOD = 1e9 + 9;
const ll inf = 1e10;
const db pi = acos(-1);
const db eps = 1e-9;

bool isPrime(ll n) {
    if(n == 1LL) return false;
    ll num = n;
    for(ll i = 2; i*i <= n; i ++) {
        while(n%i == 0)
            n /= i;
    }
    return (n == num);
}

ll nextPrime(ll x) {
    if( isPrime(x) ) return x;
    for(x = max(2LL, x + 1LL); x%6; x ++) {
        if( isPrime(x) ) return x;
    }
    
    for(; true; x += 6LL) {
        if( isPrime(x + 1LL) ) return x + 1LL;
        if( isPrime(x + 5LL) ) return x + 5LL;
    }
}

int len(ll x) {
    return floor(log10(x)) + 1;
}

ll pow(int d) {
    ll p = 1LL;
    for(int i = 1; i <= d; i ++)
        p *= 10LL;
    return p;
}


int main(){

    int d;
    ll nn;
    cin >> d >> nn;
  
    vector<ll> digits;
    ll aux = nn;
    while(aux) {
        digits.pb( aux%10LL );
        aux /= 10LL;
    }
    digits.pb(0);
    reverse(digits.begin(), digits.end());
    ll ans = (1LL<<60LL);
    ll num = 0;
    int n = digits.size() - 1;
    
    for(int i = 1; i <= n; i ++) {
        num = num * 10LL + digits[i];
        
        ll a = nextPrime( max( pow(d - 1LL), num ) );
        ll b = nextPrime( (a > num) ? max(pow(n - i - 1LL), pow(d - 1LL)) : max( pow(d - 1LL) ,nn - num * pow(n - i)) ); 
        // cout << i << " -> " << a << ' ' << b << endl;
        ll number = a * pow(len(b)) + b;
        ans = min(ans, number);    
    }

    cout << ans;

}