#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 2e5 + 1;
ll dp[maxn]; 

int main(){

   int n, q;
   cin >> n >> q;
   for(int i = 1; i <= n; i ++) {
       ll x; cin >> x;
        dp[i] = dp[i - 1] + x;
   }

   while(q --) {
       int l, r;
       cin >> l >> r;
       cout << dp[r] - dp[l - 1] << '\n';
   }
}