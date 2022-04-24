#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int inf = (1<<30);
const int maxn = 2e2 + 1;

int a[maxn], b[maxn];
bool dp[maxn][ 1<<9 + 1 ];

int main(){

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= m; i ++) cin >> b[i];

    for(int i = 1; i <= m; i ++) {
        dp[1][ a[1]&b[i] ] = true;
    }

    for(int i = 2; i <= n; i ++) {
        for(int k = 0; k <= (1<<9); k ++) {
            
            if( !dp[i - 1][k] ) continue;
            for(int j = 1; j <= m; j ++) {
                dp[i][ k|(a[i]&b[j]) ] = true;
            }
        }
    }


    for(int i = 0; i <= (1<<9); i ++)
       if( dp[n][i] ) {
           cout << i << '\n';
           break;
       }

}

// https://codeforces.com/problemset/problem/1395/C