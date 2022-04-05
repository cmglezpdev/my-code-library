#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 2 * 1e4 + 1;
vector<int> g[maxn];
bool visited[maxn];
int distances[maxn];
int n, m;

void Solve() {

    fill(distances, distances+ maxn, (1<<30));
    int maxx = -(1<<30);

    queue<pair<int, int> > q;
    q.push(make_pair(1, 0));
    while(!q.empty()) {

        int u = q.front().first;
        int c = q.front().second;
        q.pop();
        distances[u] = min( distances[u], c );
        maxx = max(maxx, distances[u]);

        if(visited[u]) continue;
        visited[u] = true;

        for(auto &v : g[u]) {
            if( visited[v] ) continue;
            q.push(make_pair(v, c + 1));
        }
    }

    int cnt = 0, establo = 0;
    for(int i = 1; i <= n; i ++) {
        if( distances[i] != maxx ) continue;
        cnt ++;
        if( !establo ) establo = i;
    }

    cout << establo << ' ' << maxx << ' ' << cnt << '\n'; 
} 

int main(){

   cin >> n >> m;

        int ai, bi;
    for(int i = 1; i <=  m; i ++) {
        cin >> ai >> bi;
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    Solve();
}