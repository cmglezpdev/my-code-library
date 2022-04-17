#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int main(){

    int n, v;
    cin >> n >> v;

    vector< pair<int, int> > info;

    for(int t = 0; t < n; t ++) {
        int a, b; // a = dia que se marchitan, b = cantodad de frutas
        cin >> a >> b;
        info.push_back( make_pair(a, b) );
    }

    sort(info.begin(), info.end());

    int last = 0;
    int ans = 0;
    int day = 1;

    while( last < n ) {

        int rec = 0;
        while( last < n ) {
            if( day < info[last].first ) {
                day = info[last].first - 1;
                break;
            }
            if( day > info[last].first + 1 ) {
                last ++;
                continue;
            }
            if( rec + info[last].second <= v ) {
                rec += info[last].second;
                last ++;
            } else {
                info[last].second -= (v - rec);
                rec = v;
                break;
            }
        }

        ans += rec;
        day ++;
    }

    cout << ans;
}