#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e2 + 1;
const int maxw = 1e2 + 1;
int weigth[maxn];
int value[maxn];

int dp[maxn][maxw];
bool selected[maxn];

int Mochila(int n, int w) {

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= w; j ++) {
            if(j - weigth[i] < 0) {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weigth[i]] + value[i]);
        }
    }

    return dp[n][w];
}

void BuildSolution(int n, int w) {

    for(int i = n; i >= 1; i --) {
        if( dp[i][w] == dp[i - 1][w]) 
            continue;
        if( dp[i][w] == dp[i - 1][w - weigth[i]] + value[i] ) {
            selected[i] = true;
            w -= weigth[i]; 
        }
    }

}


void Test(int n, int w) {

    cout << Mochila(n, w) <<'\n';

    BuildSolution(n, w);
    for(int i = 1; i <= n; i ++)
        if( selected[i] ) cout << i << ' ';
}

int main() {

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        cin >> weigth[i] >> value[i];

    Test(n, m);

}
