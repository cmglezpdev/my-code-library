#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long
const int inf = (1<<30);
const int maxn = 100 + 1;
int a[maxn];
int dp[maxn][3]; // gym, contest, rest

int max(int x, int y, int z) {
    return max(x, max(y, z));
}

int main(){

    int n; cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];    

    for(int i = 1; i <= n; i ++) {
        dp[i][0] = max( dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] );
        
        if( a[i] == 1 || a[i] == 3 ) {
            dp[i][1] = max( dp[i - 1][0], dp[i - 1][2] ) + 1;
        }
        if( a[i] == 2 || a[i] == 3 ) {
            dp[i][2] = max( dp[i - 1][0], dp[i - 1][1] ) + 1;
        }
    }


    int ans = n - max( dp[n][0], max(dp[n][1], dp[n][2]) );
    cout << ans;

}