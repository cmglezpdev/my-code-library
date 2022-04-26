#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 1e3 + 1;
int forest[maxn][maxn];
int dp[maxn][maxn];

int query(int a, int b, int c, int d) {
    return dp[c][d] - dp[a - 1][d] - dp[c][b - 1] + dp[a - 1][b - 1];
}

int main(){

    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            char x; cin >> x;
            forest[i][j] = (x == '*');
        }
    }   

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + forest[i][j];
        }
    }   


    while(q --) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << query(a, b, c, d) << '\n';
    }
    
}