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

vector<int> g[maxn];   
bool visited[maxn];
map<pair<int, int>, bool> mark;
ll cntn[maxn]; // cantidad de nodos por componente
ll cnta[maxn]; // cantidad de aristas por componente
int comp = 0; // cantidad de componentes

void dfs( int u, int p ) {

    visited[u] = true;
    cntn[ comp ] ++;

    for(auto &v : g[u]) {
        if( !mark.count(mp(u, v)) ) {
            mark[ mp(u, v) ] = mark[ mp(v, u) ] = true;
            cnta[ comp ] ++;
        }

        if(visited[v]) continue;
        dfs(v, u);
    }

}

int main(){


    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
   
    for(int i = 1; i <= n; i ++) {
        if(visited[i]) continue;
        comp ++;
        dfs(i, 0);
    }


    // for(int i = 1; i <= comp; i ++)
    //     cout << cntn[i] << ' ' << cnta[i] << '\n';





    int minn = max(1, comp - k);
    int maxx = comp;

    for(int i = 1; i <= comp; i ++) {
        ll cantnodos = cntn[i];
        ll all = cantnodos * (cantnodos - 1LL) / 2LL;
        ll diff = all - cnta[i];
        k -= diff;
        if( k < 0 )
            break;
    }

    if( k > 0 ) {
        sort( cntn + 1, cntn + comp + 1, greater<int>() );
        ll aux = cntn[1];
        for(int i = 2; i <= comp; i ++) {
            ll newa = aux * cntn[i];
            k -= newa;
            maxx --;
            aux += cntn[i];
            if( k <=0 )
                break;
        }


    }

    cout << minn << ' ' << maxx << '\n';
}