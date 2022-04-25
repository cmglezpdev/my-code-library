#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 50 + 1;


int main() {

    int tt; cin >> tt;
    while(tt --) {
        int n; cin >> n;
        bool polygon[n][n];

        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                char x; cin >> x;
                polygon[i][j] = ( x == '1' );
            }
        }
    
        bool ok = true;
        for(int i = n - 1; i >= 0; i --) {
            for(int j = n - 1; j >= 0; j --) {
                if( !polygon[i][j] ) continue;
                if( j == n - 1 || i == n - 1 ) continue;
                if( polygon[i + 1][j] || polygon[i][j + 1] ) continue;
                ok = false;
                break;
            }

            if( !ok ) break;
        }

        (ok) ? cout << "YES\n" : cout << "NO\n";
    }
    
}