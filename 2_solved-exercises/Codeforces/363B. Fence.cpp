#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 15e4 + 1;
int a[maxn];
int dp[maxn];

int main(){

    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        dp[i] = dp[i - 1] + a[i]; 
    }

    int ans = 1, s = (1<<30);
    for(int i = 1; i + k - 1 <= n; i ++) {
        int as = dp[i + k - 1] - dp[i - 1];
        if( as < s ) {
            s = as;
            ans = i;
        }
    }

    cout << ans;
}