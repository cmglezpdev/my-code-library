#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 5e3 + 1;
int dp[maxn][maxn];

int min(int a, int b, int c) {
    return min(min(a, b), c);
}

int main(){

    string a, b;
    cin >> a >> b;
    int na = a.size(), nb = b.size();
    a = ' ' + a;
    b = ' ' + b;

    dp[0][0] = 0;
    for(int i = 1; i <= max(na, nb); i ++)
        dp[0][i] = dp[i][0] = i;


    for(int i = 1; i <= na; i ++) {
        for(int j = 1; j <= nb; j ++) {
            int s = (a[i] == b[j]) ? 0 : 1;
            dp[i][j] = min( dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + s );       
        }
    }

    cout << dp[na][nb];
}