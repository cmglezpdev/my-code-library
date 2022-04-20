#include<bits/stdc++.h>

using namespace std;

const int maxn = 50005;
#define two pair<int, int>
#define F first
#define S second
#define pb push_back
vector<two> g[maxn];
const int oo = 1e9;
vector<int> best(maxn, oo);
priority_queue<two, vector<two>, greater<two> > q;

int Dijkstra(int x, int en){
    q.push(two(0, x));
    best[x] = 0;

    while( !q.empty() ){

        int node = q.top().S;
        int cost = q.top().F;
        q.pop();

        for( auto i : g[node] ){
            int newn = i.F;
            int newc = cost + i.S;
            if( best[newn] > newc ){
                best[newn] = newc;
                q.push(two(newc, newn));
            }
        }

    }
    return best[en];
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;


    for(int i = 0; i < m; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].pb(two(b, c));
        g[b].pb(two(a, c));
    }

    cout << Dijkstra(1, n);
}