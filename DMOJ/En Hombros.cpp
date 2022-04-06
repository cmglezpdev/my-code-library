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
const int maxn = 4 * 1e4 + 1;
const int MOD = 1e9 + 9;
const ll inf = 1e9;
const db pi = acos(-1);
const db eps = 1e-9;
int B, E, P, N, M;
vector<int> g[maxn];
int auxPath[maxn];
int pathB[maxn];
int pathE[maxn];
int pathP[maxn];

void MinPath(int start, char crow) {
    fill(auxPath, auxPath + maxn, inf);
    
    priority_queue< PII, vector<PII>, greater<PII> > q;
    q.push( mp(0, start) );
    auxPath[start] = 0;
    while(!q.empty()) {

        int u = q.top().s;
        int c = q.top().f;
        q.pop();
        auxPath[u] = min( auxPath[u], c );

        for(auto &v : g[u]) {
            if( c + 1 < auxPath[v] ) {
                auxPath[v] = c + 1;
                q.push(mp(c + 1, v));
            }
        }
    }

    for(int i = 1; i <= N; i ++) {
        if( crow == 'B' ) pathB[i] = auxPath[i];
        else
        if( crow == 'E' ) pathE[i] = auxPath[i];
        else
        if( crow == 'P' ) pathP[i] = auxPath[i];
    }

}


int main(){

   cin >> B >> E >> P >> N >> M;
   for(int i = 1; i <= M; i ++) {
       int x, y;
       cin >> x >> y;
       g[x].pb(y);
       g[y].pb(x);
   }

    MinPath(1, 'B');
    MinPath(2, 'E');
    MinPath(N, 'P');

    int solution = inf;
    for(int i = 1; i <= N; i ++) {
        int aux = pathB[i] * B + pathE[i] * E + pathP[i] * P;
        solution = min(solution, aux);
    }

    cout << solution;

}