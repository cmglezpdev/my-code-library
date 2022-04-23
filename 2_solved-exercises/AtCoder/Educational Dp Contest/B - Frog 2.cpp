#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 1e5 + 1;

int main(){

    int n, k; cin >> n >> k;
    vector<ll> h(n + 1);
    h[0] = 0;
    for(int i = 1; i <= n; i ++)
        cin >> h[i];

    vector<ll> dp(n + 1, 1e15);
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= k && i + j <= n; j ++) {
            dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
        }
    }

    cout << dp[n] << '\n';
}