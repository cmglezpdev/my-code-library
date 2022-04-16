#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 100 + 1;
string ADNCM[maxn];
string ADNSM[maxn];

int main(){

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> ADNCM[i];
    }
    for(int i = 1; i <= n; i ++) {
        cin >> ADNSM[i];
    }

    int ans = 0;
    for(int i = 0; i < m; i ++) {
        map<char, bool> mm;
        for(int j = 1; j <= n; j ++) {
            mm[ ADNCM[j][i] ] = true;
        }
        bool ok = true;
        for(int j = 1; j <= n; j ++) {
            if( mm[ ADNSM[j][i] ] == true ) {
                ok = false;
                break;
            }
        }

        if( ok ) ans ++; 
    }

    cout << ans;

}