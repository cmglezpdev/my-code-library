#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

int max(int x, int y, int z) {
    return max(x, max(y, z));
}

const int maxn = 1e5 + 1;

int main(){

    int tt; cin >> tt;
    while(tt --) {

        int ass, bb, cpp;
        cin >> ass >> bb >> cpp;

        if( ass > cpp ) swap(ass, cpp);

        int ga, gb, gc;
        ga = ass; gb = cpp / 2; gc = cpp - gb;

        int maxx = max(ga, gb, gc);
        if( bb - (maxx - ga) >= 0 ) {
            bb -= (maxx - ga);
            ga = maxx;
        }
        if( bb - (maxx - gb) >= 0 ) {
            bb -= (maxx - gb);
            gb = maxx;
        }
        if( bb - (maxx - gc) >= 0 ) {
            bb -= (maxx - gc);
            gc = maxx;
        }

        if( ga + bb <= maxx ) ga += bb, bb = 0;
        else if( gb + bb <= maxx ) gb += bb, bb = 0;
        else if( gc + bb <= maxx ) gc += bb, bb = 0;

        int c = bb / 3;
        ga += c; gb += c; gc += c;
        c = (bb - 3 * c);
        if( c ) ga ++, c --;
        if( c ) gb ++, c --;

        cout << max(ga, gb, gc) << '\n';
    }   
}