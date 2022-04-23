#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 1e5 + 1;
int dp[maxn][4];

int main(){

    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);

    for(int i = 1; i <= n; i ++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    dp[1][1] = a[1];
    dp[1][2] = b[1];
    dp[1][3] = c[1];

    for(int i = 2; i <= n; i ++) {
        dp[i][1] = max( dp[i - 1][2] + a[i], dp[i - 1][3] + a[i] );
        dp[i][2] = max( dp[i - 1][1] + b[i], dp[i - 1][3] + b[i] );
        dp[i][3] = max( dp[i - 1][1] + c[i], dp[i - 1][2] + c[i] );
    }

    cout << max( dp[n][1], max(dp[n][2], dp[n][3]) );

}   