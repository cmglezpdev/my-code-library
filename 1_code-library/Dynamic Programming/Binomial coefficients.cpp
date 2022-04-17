#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e2;
typedef long long ll;

ll dp[maxn][maxn];

ll Comb(int n, int k) {

    if(dp[n][k]) 
        return dp[n][k];

    for(int i = 0; i <= n; i ++)
        dp[n][0] = dp[i][i] = 1LL;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j < i; j ++ ) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[n][k];
}

int main() {

    Comb(5, 4);

}