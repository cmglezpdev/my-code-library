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

int main(){

    FAST
    int n, m;
    cin >> n >> m;

    set<int> visit;
    vector< set<int> > g(n);

    for(int i = 0; i < n; i ++) 
        visit.insert(i);

    for(int i = 0; i < m; i ++) {
        int x, y; 
        cin >> x >> y;
        x --, y --;
        g[x].insert(y);
        g[y].insert(x);
    }


    int scc = 0;
    vector<int> adj;
    for(int u = 0; u < n; u ++) {
        if( visit.count(u) ) {
           
            scc ++;
            queue<int> q;
            q.push(u);
            visit.erase(u);

            while(!q.empty()) {
                int v = q.front();
                q.pop();

                adj.clear();
                for(auto &node: visit) {
                    if( !g[v].count(node) )
                        adj.pb(node);
                }

                for(auto &a: adj)   
                    q.push(a), visit.erase(a);
            }

        }
    }

    cout << scc - 1;
}