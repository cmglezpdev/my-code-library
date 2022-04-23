#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 101;
const int maxp = 1e5 + 1;

ll dp[maxn][maxp];
ll w[maxn];
ll v[maxn];

int main(){

    int n, W;
    cin >> n >> W;

    for(int i = 1; i <= n; i ++) {
        cin >> w[i] >> v[i];
    }
    
    // dp[0][i] = dp[i][0] = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= W; j ++) {
            dp[i][j] = dp[i - 1][j];
            if( j >= w[i] ) 
                dp[i][j] = max( dp[i - 1][j], dp[i - 1][j - w[i]] + v[i] );
        }
    }

    cout << dp[n][W] << '\n';
}