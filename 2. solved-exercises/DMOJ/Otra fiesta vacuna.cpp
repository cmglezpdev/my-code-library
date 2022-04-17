#include<bits/stdc++.h>

using namespace std;
#define MP make_pair
#define F first
#define S second
#define MAXN 1010
#define INF 1e9

vector<pair< int, int > > G[MAXN];
priority_queue< pair<int, int>, vector<pair< int, int > >, greater< pair<int, int> > > q;
vector< int > best(MAXN, INF);

void Dijkstra( int x ){

    q.push( MP( x, 0 )  );
    while( !q.empty() ){
        int node = q.top().F;
        int cost = q.top().S;
        q.pop();
        for(int i = 0; i < (int)G[node].size(); i ++){
            int nnode = G[node][i].F;
            int ncost = G[node][i].S + cost;
            if( ncost < best[nnode] ){
                best[nnode] = ncost;
                q.push( MP( nnode, ncost ) );
            }

        }
    }
}


void Dijkstra_step( int x, int dest ){

    priority_queue< pair<int, int>, vector<pair< int, int > >, greater< pair<int, int> > > A;

    vector<int> mejor( MAXN, INF );
    A.push( MP( x, 0 ) );
    bool flag = 0;
    while( !A.empty() ){
         int node = A.top().F;
         int cost = A.top().S;
          A.pop();
          for(int i = 0; i < G[node].size(); i ++){
                int nnode = G[node][i].F;
                int ncost = G[node][i].S + cost;
                if( mejor[nnode] > ncost ){
                    mejor[nnode] = ncost;
                    A.push( MP( nnode, ncost ) );
                }
                if( nnode == dest ) break;
          }
    }
    if( mejor[dest] < INF )
        best[x] += mejor[dest];

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen( "data.in", "r", stdin );

    int n, m, x;
    cin >> n >> m >> x;

    for(int i = 0; i < m; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back( MP( b, c ) );
    }

    Dijkstra( x );

    int sol = 0;

    for(int i = 1; i <= n; i ++){
        if( i == x ) continue;
        Dijkstra_step( i, x );
        sol = max( sol, best[i] );
    }
     cout << sol;

}