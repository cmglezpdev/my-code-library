#include<bits/stdc++.h>
 
using namespace std;

const int maxn = 1e5 + 1;
vector<int> g[maxn];
bool mark[maxn];

bool buss(int u) {

    mark[u] = true;

    if( g[u].size() > 2 ) return false;

    for(auto v : g[u]) {
        if( mark[v] ) continue;
        return buss( v );
    }
    return ( g[u].size() == 1 ) ? true : false;
}

bool ring(int u) {

    mark[u] = true;

    if( g[u].size() != 2 ) return false;

    for(auto v : g[u]) {
        if( mark[v] ) continue;
        return ring( v );
    }
    return true;
}

bool star( int n ) {

    for(int i = 1; i <= n; i ++) {
        if( g[i].size() > 1 && g[i].size() != n - 1 ) return false;

        if( g[i].size() == n - 1 ) {
            for(auto &v: g[i]) {
                if( g[v].size() != 1 ) return false;
            }
            return true;
        }   

    }
    return false;
}


int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    int n,  m;
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int a, b; 
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // buss : tiene que tener n - 1 aristas
    // ring : tiene que tener n aristas
    // star : tiene que tener n - 1 aristas;
 
    if( m == n - 1 && buss(1) ) {
        cout << "bus topology\n";
        return 0;
    }

    fill(mark, mark + maxn, false);
    if( m == n && ring(1) ) {
         cout << "ring topology\n";
         return 0;
    }

    if( m == n - 1 && star(n) ) {
         cout << "star topology\n";
         return 0;
    }

    cout << "unknown topology\n";
}