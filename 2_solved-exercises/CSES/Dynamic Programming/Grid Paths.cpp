#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 1e3 + 1;
const int mod = 1e9 + 7;

char board[maxn][maxn];
int dp[maxn][maxn];

int main(){

    int n; cin >> n;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            cin >> board[i][j];
        }
    }
    dp[1][1] = (board[1][1] == '*') ? 0 : 1;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            if(i == 1 && j == 1) continue;
            if(board[i][j] == '*') continue;
            dp[i][j] = (long long)(dp[i - 1][j] + dp[i][j - 1])%mod;
        }
    }
    cout << dp[n][n] << '\n';
}