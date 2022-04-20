#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back
#define two pair<int, double>
#define twoi pair<double, int>
#define mp make_pair
const int maxn = 100005;
vector<two> g[maxn];
map<pair<int, int>, int> id;
char dan[maxn];
double best[maxn];

double Dijkstra(int a, int b){
    fill(best, best + maxn, (double)1e9);
    priority_queue<twoi, vector<twoi>, greater<twoi> > q;
    q.push(mp(0.00, a));
    best[a] = 0.00;
    while(!q.empty()){
        int node = q.top().S;
        double cost = q.top().F;
        q.pop();
        for(auto i : g[node]){
            int newn = i.F;
            double newc = cost + i.S;
            if( dan[ id[mp(node, newn)] ] == 'D' ) continue;
            if( best[newn] > newc ){
                best[newn] = newc;
                q.push(mp(newc, newn));
            }
        }
    }

    return best[b];
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, c, x, y;
    cin >> n >> m >> c >> x >> y;
    for(int i = 0; i < m; i ++){
        int f, a, b;
        double z;
        cin >> f >> a >> b >> z;
        id[mp(a, b)] = f;
        id[mp(b, a)] = f;
        g[a].pb(two(b, z));
        g[b].pb(two(a, z));
    }
    fill(dan, dan + maxn, 'P');
    for(int i = 0; i < c; i ++){
        int k; cin >> k;
        dan[k] = 'D';
    }

    cout.precision(2);
    cout << fixed << Dijkstra(x, y);

}