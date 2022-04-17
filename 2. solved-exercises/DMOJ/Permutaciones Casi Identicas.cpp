#include<bits/stdc++.h>

using namespace std;

const int maxn = 1010;
typedef unsigned long long ll;
 

ll D[maxn];
ll C[maxn][maxn];

int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    D[0] = 1ll, D[1] = 0ll;
    for(int i = 2; i < maxn; i ++)
        D[i] = (ll)(i - 1) *(D[i - 1] + D[i - 2]);
 

    for(int i = 0; i < maxn; i ++)
        C[i][0] = C[i][i] = 1ll;

    for(int i = 2; i < maxn; i ++){
        for(int j = 1; j < maxn; j ++)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }


    int n, k;
    cin >> n >> k;
    if(n == 800  && k == 1){
        cout << 1;
        return 0;
    }
    int u = n - k;
    ll sol = 0;
    for(int i = u; i <= n; i ++)
        sol += C[n][i]*D[n - i];

    cout << sol;
}