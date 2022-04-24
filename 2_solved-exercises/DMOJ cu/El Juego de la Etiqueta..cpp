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
const int maxn = 2e5 + 1;
const int MOD = 1e9 + 9;
const ll inf = 1e10;
const db pi = acos(-1);
const db eps = 1e-9;
 
vector<int> graph[maxn];
int lv[maxn];
int mxlv[maxn];
 
void dfs(int u, int p) {
 
    lv[u] = lv[p] + 1;
    mxlv[u] = max( mxlv[u], lv[u] );
 
    for(auto &v: graph[u]) {
        if( v == p ) continue;
        dfs(v, u);
        mxlv[u] = max(mxlv[u], mxlv[v]);
    }
 
}
 
int ans = 0;
 
void dfsr(int u, int x) {
 
    if( mxlv[u] >= mxlv[x] ) {
 
        if( abs(lv[x] - lv[u]) < lv[u] - 1 ) {
            int tour_a = mxlv[u] - 1;
            int tour_b = abs(lv[x] - lv[u]) + abs(mxlv[u] - lv[u]);
            ans = max( ans, tour_a + tour_b + max(0, tour_a - tour_b) );
        }
    }
 
    for(auto &v: graph[u]) {
        if( lv[v] + 1 != lv[u] ) continue;
        dfsr(v, x);
    }
 
}
 
int main(){
 
    FAST
 
    int n, x;
    cin >> n >> x;
 
    for(int i = 1; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
    dfs(1, 0);
    dfsr(x, x);
 
    cout << ans;
 
 
}