#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 1e5 + 1;

int main(){

    int n; cin >> n;
    int h[n], m[n], d[n];
    
    int dt = 0, ht = 0, mt = 0;
    int day = 0;
    double vm = 0;
    for(int i = 0; i < n; i ++) {
        cin >> h[i] >> m[i] >> d[i];
        ht += h[i];
        mt += m[i];

        // velocidad
        int tm = m[i] + h[i] * 60;
        int dm = d[i] * 1000;
        double v = (double)((double)dm / (double)tm);
        if( v > vm ) {
            vm = v;
            day = i + 1;
        }
    }

    ht += (mt / 60);
    mt -= ((mt / 60) * 60);
    dt += ht / 24;
    ht -= ((ht / 24) * 24);

    cout << dt << ' ' << ht << ' ' << mt << ' ' << day;
}