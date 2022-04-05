#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

int max(int x, int y, int z) {
    return max(x, max(y, x));
}

const int maxn = 1e4 + 1;
int dp[maxn];

int main(){

    FAST

    int X, Y, M;
    cin >> X >> Y >> M;

    dp[0] = 0;

    for(int i = 1; i <= M; i ++){
        int x = ( i - X >= 0 ) ? dp[i - X] + X : 0;
        int y = ( i - Y >= 0 ) ? dp[i - Y] + Y : 0;
        int z = dp[i - 1];

        dp[i] = max( x, y, z );
    }

    cout << dp[M] << '\n';
}