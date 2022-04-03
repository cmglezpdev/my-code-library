#include<bits/stdc++.h>

using namespace std;

#define db int
const int maxn = 2001;
struct point{
    db x, y;
    point(db a, db b){
        x = a, y = b;
    }
};

db dist( point a, point b){
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

vector< pair<db, pair<int, int> > > v;
int parent[maxn], sz[maxn];

void init(int n){
    sort(v.begin(), v.end());
    for(int i = 1; i <= n; i ++) parent[i] = i, sz[i] = 1;
}

int findS(int x){
    return (parent[x] == x) ? x : findS(parent[x]);
}

void unionS(int x, int y){
    int px = findS(x);
    int py = findS(y);

    if(sz[px] > sz[py]) parent[py] = px;
    else parent[px] = py;
   sz[py] += (sz[px] == sz[py]);
}

pair<db, bool> kruskal(int n, db cost){
    db sol = 0;
    int cont = 0;
    init(n);
    for(auto w : v){
    	if(w.first < cost) continue;
        int px = findS(w.second.first);
        int py = findS(w.second.second);
        if(px != py){
            sol += w.first;
            cont ++;
            unionS(px, py);
        }
    }
    return {sol, (cont >= (n - 1))};
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; db c;
    cin >> n >> c;
    vector<point> u;
    for(int i = 1; i <= n; i ++){
        db x, y; cin >> x >> y;
        u.push_back({x, y});
    }
    for(int i = 0; i < n; i ++){
        for(int j = i + 1; j < n; j ++){
            v.push_back(make_pair(dist(u[i], u[j]), make_pair(i + 1, j + 1)));
        }
    }
    pair<db, bool> sol = kruskal(n, c);
    if( !sol.second ) cout << -1;
    else cout << sol.first;
}