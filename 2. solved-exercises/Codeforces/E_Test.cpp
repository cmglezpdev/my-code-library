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
const ll MOD = 1e9 + 9;
const ll BASE = 31LL;
const ll inf = 1e10;
const db pi = acos(-1);
const db eps = 1e-9;
ll Pow[maxn];


ll Mult(ll a, ll b, ll m) {
    if(a * b < m) return a * b;
    ll q = a * b / m;
    ll r = a * b - q * m;
    return r;
}

ll Add(ll a, ll b, ll m){
    a += b;
    if(a >= m) a-= m;
    return a; 
}

void buildPow(){
    Pow[0] = 1ll;
    for(int i = 1; i < maxn; i ++)
        Pow[i] = Mult(Pow[i - 1], BASE, MOD);
}

pair<vector<ll>, ll> getHashCode(string a) {
    int n = a.size();
    vector<ll> h(n + 1);
    h[0] = 0;
    for(int i = 0; i < a.size(); i ++) {
        h[i + 1] = Mult(h[i], BASE, MOD);
        h[i + 1] = Add(h[i + 1], a[i], MOD);
    }
    return mp(h, h[n]);
}

bool Sub(string a, string b) {
    if( a.size() > b.size() ) return false;
    int n = a.size(), m = b.size();
    ll hasha = getHashCode(a).s;
    vector< ll > hashb = getHashCode(b).f;

    for(int i = 1; i + n - 1 <= m; i ++) {
        int l = i, r = i + n - 1;
        ll h = Mult( hashb[l - 1], Pow[r - l + 1], MOD);
        h = ((hashb[r] - h)%MOD + MOD)%MOD;
        if( hasha == h ) return true;
    }
    return false;
}

string Join( string a, string b ){
    if( Sub(a, b) ) return b;
    if( Sub(b, a) ) return a;

    vector<ll> ha = getHashCode(a).f;
    vector<ll> hb = getHashCode(b).f;
    int n = a.size(), m = b.size();
    int maxx = 0;
    for(int i = 1; i <= min(n, m); i ++) {
        int l = n - i + 1, r = n;
        ll gha = Mult( ha[l - 1], Pow[r - l + 1], MOD);
        gha = ((ha[r] - gha)%MOD + MOD)%MOD; 
    
        l = 1; r = i;
        ll ghb = Mult( hb[l - 1], Pow[r - l + 1], MOD);
        ghb = ((hb[r] - ghb)%MOD + MOD)%MOD; 

        if( gha == ghb ) {
            maxx = i;
        }
    }

    string join = a + b.substr(maxx);
    return join;
}

int main(){

    FAST

    buildPow();

    string c[4];
    cin >> c[1] >> c[2] >> c[3];
    int perm[] = {1, 2, 3};
    
    int minn = (1<<30);

    do{
        string x = c[ perm[0] ], 
               y = c[ perm[1] ],
               z = c[ perm[2] ];

        string join = Join(x, y);
        join = Join(join, z);
        minn = min( minn, (int)join.size() );
    }while( next_permutation(perm, perm + 3) );

    cout << minn;
}