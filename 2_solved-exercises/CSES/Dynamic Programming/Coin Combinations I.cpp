#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 1e6 + 1;
const ll mod = 1e9 + 7;
ll dp[maxn];


int main(){

    int n, x;
    cin >> n >> x;

    int coins[n];
    for(int i = 0; i < n; i ++)
        cin >> coins[i];

    dp[0] = 1LL;
    for(int i = 1; i <= x; i ++) {
        for(int j = 0; j < n; j ++) {
            if( i - coins[j] < 0 ) continue;
            dp[i] = (dp[i] + dp[i - coins[j]])%mod;
        }
    }
    dp[0] = 0;
    cout << dp[x];
}


