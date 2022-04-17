// https://codeforces.com/contest/446/problem/C
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
const ll inf = 1e9;
const int maxn = 3e5 + 9;
const ll MOD = 1e9 + 9;
const double pi = acos(-1);
const db eps = 1e-9;
 
ll Add(ll a, ll b, ll m) {
   ll result = ((a + b)%MOD + MOD)%MOD;
    return result;
}
 
ll Subs(ll a, ll b, ll m) {
    ll result = ((a - b)%MOD + MOD)%MOD;
    return result;
}
 
ll Mult(ll a, ll b, ll m) {
    ll result = ((a * b)%MOD + MOD)%MOD;
    return result;
}
 
ll F[maxn];
ll st[4 * maxn];
struct lzy {
    ll f, s;
}lazy[4 * maxn];

ll arr[maxn];
 
void build_st(int node, int l, int r) {
    if(l == r) {
        st[node] = arr[l]%MOD;
        return;
    }
    
    int piv = (l + r) / 2;
    int ls = 2 * node, rs = ls + 1;
 
    build_st(ls, l, piv);
    build_st(rs, piv + 1, r);
 
    st[node] = Add(st[ls], st[rs], MOD);
}
 
//* Get k-th Fibonacci number where frist and second fibonacci are a and b
ll get_kth(ll a, ll b, int k) {
    a %= MOD;
    b %= MOD;
    if( k == 1 ) return a%MOD;
    if( k == 2 ) return b%MOD;

    return Add(Mult(a, F[k - 2], MOD), Mult(b, F[k - 1], MOD), MOD);
}

void propagate_st(int node, int l, int r) {
    if( lazy[node].f == 0LL && lazy[node].s == 0LL ) return; 
    
    if( l == r ) {
        st[node] = Add(st[node], lazy[node].f, MOD);
    } else {
        int len = (r - l + 1);
        //* sum of fib[1]+fib[2]+...+fib[len]=fib[len+2]-fib[2];
        st[node] = Add(st[node], Subs(get_kth(lazy[node].f, lazy[node].s, len + 2), lazy[node].s, MOD ), MOD);

        int ls = 2*node, rs = ls + 1;
        int mid = (l + r) / 2;
        lazy[ls].f = Add(lazy[ls].f, lazy[node].f, MOD);
        lazy[ls].s = Add(lazy[ls].s, lazy[node].s, MOD);

        lazy[rs].f = Add(lazy[rs].f, get_kth(lazy[node].f, lazy[node].s, mid - l + 1 + 1), MOD);
        lazy[rs].s = Add(lazy[rs].s, get_kth(lazy[node].f, lazy[node].s, mid - l + 1 + 2), MOD); 
    }

    lazy[node].f = lazy[node].s = 0;
}
 
ll query_st(int node, int l, int r, int lq, int rq) {
    propagate_st(node, l, r);
    if( lq > r || rq < l ) return 0;
    if(lq <= l && rq >= r) return st[node]%MOD;
 
    int piv = (l + r) / 2;
    int ls = 2 * node, rs = ls + 1;
    
    return Add( query_st(ls, l, piv, lq, rq), query_st(rs, piv + 1, r, lq, rq), MOD );
} 
 
 
void update_st(int node, int l, int r, int lu, int ru) {
    propagate_st(node, l, r);
    if( lu > r || ru < l ) return;
    if(lu <= l && ru >= r) {
        lazy[node].f = Add(lazy[node].f, F[l - lu + 1], MOD);
        lazy[node].s = Add(lazy[node].s, F[l - lu + 2], MOD);
        propagate_st(node, l, r);
        return;
    }
 
    int piv = (l + r) / 2;
    int ls = 2 * node, rs = ls + 1;
    
    update_st(ls, l, piv, lu, ru);
    update_st(rs, piv + 1, r, lu, ru);
 
    st[node] = Add( st[ls], st[rs], MOD );
}
 
int main(){
 
    FAST
 
    F[1] = F[2] = 1LL;
    for(int i = 3; i < maxn; i ++)
        F[i] = Add(F[i - 1], F[i - 2], MOD);
 
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> arr[i];
 
    build_st(1, 1, n);
 
    while(m --) {
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1)
            update_st(1, 1, n, l, r);
        if(op == 2) {

            ll ans = (query_st(1, 1, n, l, r)%MOD + MOD) % MOD;
            cout << ans << '\n';
        }
    }
}

/**
Solution: YouKn0wWho

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpll vector<pll>
#define vpii vector<pii>
#define umap unordered_map
#define uset unordered_set
#define PQ priority_queue

#define printa(a,L,R) for(int i=L;i<R;i++) cout<<a[i]<<(i==R-1?'\n':' ')
#define printv(a) printa(a,0,a.size())
#define print2d(a,r,c) for(int i=0;i<r;i++) for(int j=0;j<c;j++) cout<<a[i][j]<<(j==c-1?'\n':' ')
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define fbo find_by_order
#define ook order_of_key
#define MP make_pair
#define UB upper_bound
#define LB lower_bound
#define SQ(x) ((x)*(x))
#define issq(x) (((ll)(sqrt((x))))*((ll)(sqrt((x))))==(x))
#define F first
#define S second
#define mem(a,x) memset(a,x,sizeof(a))
#define inf 0x3f3f3f3f
#define PI (acos(-1.0))
#define E 2.71828182845904523536
#define gamma 0.5772156649
#define nl "\n"
#define lg(r,n) (int)(log2(n)/log2(r))
#define pf printf
#define sf scanf
#define _ccase printf("Case %lld: ",++cs)
#define _case cout<<"Case "<<++cs<<": "
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; }

#define asche cerr<<"Ekhane asche\n";
#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<int>())
#define all(v) v.begin(),v.end()
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define toint(a) atoi(a.c_str())
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
#define valid(tx,ty) (tx>=0&&tx<n&&ty>=0&&ty<m)
#define one(x) __builtin_popcount(x)
#define Unique(v) v.erase(unique(all(v)),v.end())
#define stree ll l=(n<<1),r=l+1,mid=b+(e-b)/2
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ll dx[]={1,0,-1,0,1,-1,-1,1};
//ll dy[]={0,1,0,-1,1,1,-1,-1};

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}

const int mod=1e9+9;
const int mxn=3e5+9;
const ld eps=1e-9;
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}
struct seg
{
    ll fi,se;
}lazy[mxn*4];
ll t[mxn*4],f[mxn],a[mxn];
//get k-th fibonacci number where first and second fibonacci is a and b
ll get_kth(ll a,ll b,ll k)
{
    a%=mod;
    b%=mod;
    if(k==1) return a;
    if(k==2) return b;
    return ((a*f[k-2])%mod+(b*f[k-1])%mod)%mod;
}
void propagate(ll n,ll b,ll e)
{
    if(lazy[n].fi==0&&lazy[n].se==0) return;
    if(b==e) t[n]=(t[n]+lazy[n].fi)%mod;
    else{
        ll len=e-b+1;
        //sum of fib[1]+fib[2]+...+fib[len]=fib[len+2]-fib[2];
        t[n]=(t[n]+((get_kth(lazy[n].fi,lazy[n].se,len+2)-lazy[n].se)%mod+mod)%mod)%mod;
        lazy[2*n].fi=(lazy[2*n].fi+lazy[n].fi%mod)%mod;
        lazy[2*n].se=(lazy[2*n].se+lazy[n].se%mod)%mod;
        ll mid=(b+e)/2;
        lazy[2*n+1].fi=(lazy[2*n+1].fi+get_kth(lazy[n].fi,lazy[n].se,mid-b+1+1))%mod;
        lazy[2*n+1].se=(lazy[2*n+1].se+get_kth(lazy[n].fi,lazy[n].se,mid-b+1+2))%mod;
    }
    lazy[n].fi=lazy[n].se=0;
}
void build(ll n,ll b,ll e)
{
    if(b==e){
        t[n]=a[b]%mod;
        return;
    }
    stree;
    build(l,b,mid);
    build(r,mid+1,e);
    t[n]=(t[l]+t[r])%mod;
}
void upd(ll n,ll b,ll e,ll i,ll j)
{
    propagate(n,b,e);
    if(i>e||j<b) return;
    if(b>=i&&e<=j){
        lazy[n].fi=(lazy[n].fi+f[b-i+1])%mod;
        lazy[n].se=(lazy[n].se+f[b-i+2])%mod;
        propagate(n,b,e);
        return;
    }
    stree;
    upd(l,b,mid,i,j);
    upd(r,mid+1,e,i,j);
    t[n]=(t[l]+t[r])%mod;
}
ll query(ll n,ll b,ll e,ll i,ll j)
{
    propagate(n,b,e);
    if(i>e||j<b) return 0;
    if(b>=i&&e<=j) return t[n]%mod;
    stree;
    return (query(l,b,mid,i,j)+query(r,mid+1,e,i,j))%mod;
}
int main()
{
    fast;
    ll i,j,k,n,m,t,l,r;
    f[1]=f[2]=1;
    for(i=3;i<mxn;i++) f[i]=(f[i-1]+f[i-2])%mod;
    cin>>n>>m;
    for(i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while(m--){
        cin>>t>>l>>r;
        if(t==1) upd(1,1,n,l,r);
        else cout<<(query(1,1,n,l,r)+mod)%mod<<nl;
    }
    return 0;
}



**/