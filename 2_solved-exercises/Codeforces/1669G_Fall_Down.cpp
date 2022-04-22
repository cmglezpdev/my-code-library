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
        int n, m;
        cin >> n >> m;

        char board[n + 1][m + 1];
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                cin >> board[i][j];
            }
        }

        vector<int> last(m + 1, n);
        for(int i = 1; i <= m; i ++) {
            while(  last[i] >= 1 && board[ last[i] ][i] != '.' ) last[i] --;
        }

        for(int i = n - 1; i >= 1; i --) {
            for(int j = 1; j <= m; j ++) {
                if( last[j] < i ) continue;
                if( board[i][j] == 'o' ) {
                    last[j] = i - 1;
                    continue;
                }
                if( board[i][j] == '*' ) {
                    board[i][j] = '.';
                    board[ last[j] ][j] = '*';
                    last[j] --;
                }
            }
        }

        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++)
                cout << board[i][j];
            cout << '\n';
        }

        cout << '\n';


    }
}