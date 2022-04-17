#include<bits/stdc++.h>
 
using namespace std;
 
const int maxn = 2 * 1e5 + 1;
long long dp[maxn];
const long long inf = -(1<<30) * 1LL;
 
long long f( int x, int y, int B, int i_element ) {
 
    if(i_element == 0) {
        return dp[0] = 0;
    }
 
    if( dp[i_element] != inf)
        return dp[ i_element ];
 
    long long aux = f( x, y, B, i_element - 1) + x*1LL;
    if( aux > B ) 
        aux = inf;
    
    long long auy = f( x, y, B, i_element - 1) - y*1LL;
    if( auy > B )
         auy = inf;
 
 
    dp[i_element] = max( dp[i_element], max(dp[i_element], max( aux, auy ) ) );
    return dp[i_element];
}
 
 
int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    // freopen("input.txt", "r", stdin);
 
 
    int test;
    cin >> test;
    
    while(test --) {
        int n, B, x, y;
        cin >> n >> B >> x >> y;
 
        for(int i = 0; i < maxn; i ++)
            dp[i] = -(1<<30);
 
        f( x, y, B, n );
 
        long long sol = 0;
        for(int i = 0; i <= n; i ++)
            sol += ( dp[i] == inf ) ? 0LL : dp[i];
 
        cout << sol << endl;
    }
 
}