#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 1e5 + 1;

int main(){

    int tt; cin >> tt;
    while(tt --) {
        ll a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;

        bool footdog = false;
        if( a + c >= x ) {
            a -= x;
            if( a < 0 ) {
                c += a;
                a = 0;
            }
            footdog = true;
        }

        bool footcat = false;
        if( b + c >= y ) {
            b -= y;
            if( b < 0 ) {
                c += b;
                b = 0;
            }
            footcat = true;
        }

        ( footcat && footdog ) ? cout << "YES\n" : cout << "NO\n";

    }

}