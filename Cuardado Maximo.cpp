#include<bits/stdc++.h>

using namespace std;

const int maxn = 302;
int dp[maxn][maxn];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            cin >> dp[i][j];
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }

    int sol = -1e9;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            for(int k = i, u = j; k <= n && u <= n; k ++, u ++){
                int sub = dp[k][u] - dp[k][j - 1] - dp[i - 1][u] + dp[i - 1][j - 1];
                sol = max( sol, sub );
            }
        }
    }
    cout << sol;
}