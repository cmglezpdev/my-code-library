#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 1e5 + 1;

int main(){

    FAST

    int tt; cin >> tt;
    while(tt --) {
        int n; cin >> n;
        string s; cin >> s;
        if( n == 1 && s != "W" ) {
            cout << "NO\n";
            continue;
        } else if( n == 1 && s == "W" ) {
            cout << "YES\n";
            continue;
        }       

        int B = 0, R = 0;
        int idx = 0;
        bool ok = true;
        while(idx < n) {
            while( idx < n && s[idx] == 'W' ) idx ++;
            while( idx < n && s[idx] != 'W' ) {
                if( s[idx] == 'R' ) R ++;
                else B ++; 
                idx ++;
            }
            if( (B != 0 && R == 0) || (B == 0 && R != 0) ) {
                cout << "NO\n";
                ok = false;
                break;
            }
            B = R = 0;
        }

        if(ok) cout << "YES\n";
    }
}