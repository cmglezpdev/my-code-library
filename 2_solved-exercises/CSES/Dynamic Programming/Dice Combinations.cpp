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

    int n; cin >> n;
    dp[0] = 1;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= min(i, 6); j++)
            dp[i] = (dp[i] + dp[i - j])%mod;
    }

    cout << dp[n];

}