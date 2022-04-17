#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 61;
ll dp[maxn];

int main(){

    int n; cin >> n;
    dp[2] = 2LL;
    for(int i = 4; i <= n; i += 2) {
        dp[i] = dp[i - 2] * 2LL;
    }
   
   cout << dp[n];
}