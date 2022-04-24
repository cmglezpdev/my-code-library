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
        string s; cin >> s;
        int n = s.size();
        s = ' ' + s;
        if( s[n] != 'B' ) {
            cout << "NO\n";
            continue;
        }
        bool ok = true;
        int A = 0, B = 0;
        for(int i = 1; i <= n; i ++) {
            if( s[i] == 'A' ) A ++;
            else 
            if( s[i] == 'B' ) {
                B ++;
                if( A < B ) {
                    ok = false;
                    break;
                }
            }
        }

        if( ok ) cout << "YES\n";
        else cout << "NO\n";
    }

}   