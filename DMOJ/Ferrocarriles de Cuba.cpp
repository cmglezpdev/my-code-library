#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e2 + 1;
const int maxx = 1e4 + 1;
int A[maxn];
int B[maxn];
bool dp[maxn][maxx];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, X;
    cin >> n >> X;

    for(int i = 1; i <= n; i ++) {
        cin >> A[i];
        cin >> B[i];  
    }

    dp[0][0] = true;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= X; j ++) {
            bool x = (j - A[i] >= 0) ? dp[i - 1][j - A[i]] : false;
            bool y = (j - B[i] >= 0) ? dp[i - 1][j - B[i]] : false;

            dp[i][j] = x | y;
        }
    }

    if( dp[n][X] )
        cout << "Yes\n";
    else 
        cout << "No\n";

}