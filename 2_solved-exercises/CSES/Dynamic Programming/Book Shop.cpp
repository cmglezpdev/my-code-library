#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 1e3 + 1;
const int maxn2 = 1e5 + 1;
int h[maxn];
int s[maxn];
int dp[maxn][maxn2];

int main(){

    int n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; i ++)
        cin >> h[i];
    for(int i = 1; i <= n; i ++)
        cin >> s[i];

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= x; j ++) {
            dp[i][j] = dp[i - 1][j];
            if( j - h[i] >= 0 )
                dp[i][j] = max( dp[i][j], dp[i - 1][j - h[i]] + s[i] );
        }
    }
    cout << dp[n][x];   
}