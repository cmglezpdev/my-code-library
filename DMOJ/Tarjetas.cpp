#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define pb push_back
#define mp make_pair
#define f first
#define s second

const int maxn = 150;

vector< pair< string, pair<int, int> > > ordenes[maxn];


int times(int sh, int sm, int eh, int em) {

    if( sh == eh ) return em - sm;

    int result = 0;

    result += (60 - sm);
    sh ++; sm = 0;

    result += em;
    em = 0;
    
    result += (eh - sh) * 60;

    return result;
}


int main(){

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        int c, h, m;
        string orden;
        cin >> c >> orden >> h >> m;
        ordenes[c].pb( mp( orden, mp(h, m) ) );
    }
    vector<int> ans(n + 1, 0);

    for(int i = 1; i <= n; i ++) {

        // cout << "vaca " << i << '\n';
        stack< pair<int, int> > s;
        for( auto &v : ordenes[i] ) {
            string o = v.f;
            if( o == "START" ) {
                s.push(mp(v.s.f, v.s.s));
                continue;
            }

            int sh = s.top().f, sm = s.top().s;
            s.pop();
            int eh = v.s.f, em = v.s.s;
            // cout << sh << ' ' << sm << " -- " << eh << ' ' << sm << ' ';
            // cout << times( sh, sm, eh, em ) << '\n';
            ans[i] += times( sh, sm, eh, em );
        }
    }

    for(int i = 1; i <= n; i ++) {
        int hi = ans[i] / 60;
        int mi = ans[i] - 60 * hi;
        
        cout << hi << ' ' << mi << '\n';
    }

}