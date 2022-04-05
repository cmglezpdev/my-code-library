#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 13;
const int maxp = 1e7 + 1;
int cnt[maxn];
int price[maxn];
int dp[maxp];

int main(){

   int n, p;
   cin >> n >> p;
   
    for(int i = 1; i <= n; i ++) cin >> cnt[i];
    for(int i = 1; i <= n; i ++) cin >> price[i];

    dp[0] = 1;
    for(int i = 1; i <= n; i ++) {
        for(int j = p; j >= price[i]; j --) {
            for(int k = 1; k <= cnt[i]; k ++) {
                if( j - k * price[i] < 0 ) break;
                dp[j] += dp[j - k * price[i]];
            }
        }
    }

    cout << dp[p] << '\n';
}