#include<bits/stdc++.h>

using namespace std;

const int maxn = 100;
// int dp[maxn];
bool dp[maxn];
int a[maxn];
bool m[maxn];

bool is( int n, int idx ) {

    if(idx < 0 && n != 0) return false;

    if( dp[n] != -1 ) return dp[n];
    if(n == 0) return dp[n] = 1;

    if( n - a[idx] >= 0 ) {
        dp[n] = is(n - a[idx], idx - 1);
        if( dp[n] == 1 ) return true;
    }

    return dp[n] = is(n, idx - 1);
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    int test; cin >> test;

    while(test --) {
        int n; cin >> n;

        for(int i = 0; i < maxn; i ++) {
            a[i] = m[i] = 0;
            dp[i] = 0;
        }

        int sum = 0;
        for(int i = 0; i < n; i ++ ) {
            cin >> a[i];
            sum += a[i];
        }

        if( sum % 2 != 0 ) {
            cout << "NO\n";
            continue;
        }

        // bool ok = is( sum/2, n - 1 );

        // ( ok ) ? cout << "YES\n" : cout << "NO\n";

        dp[0] = true;
        for(int i = 1; i <= sum/2; i ++) {
            for(int j = 0; j < n; j ++) {
                if( i - a[j] >= 0 ) {
                    dp[i] = dp[i - a[j]];
                }
            }
        }

         ( dp[sum / 2] ) ? cout << "YES\n" : cout << "NO\n";
    
    }






}