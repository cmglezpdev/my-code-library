#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 1e5 + 1;

int main(){

    int n; cin >> n;
    vector<ll> h(n + 1);
    h[0] = 0;
    for(int i = 1; i <= n; i ++)
        cin >> h[i];

    vector<ll> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = abs(h[1] - h[2]);
    for(int i = 3; i <= n; i ++) {
        dp[i] = min( dp[i - 1] + abs(h[i] - h[i - 1])  , 
                     dp[i - 2] + abs(h[i] - h[i - 2]) );
    }

    cout << dp[n] << '\n';
}