#include<bits/stdc++.h>
 
using namespace std;
 
const int maxn = 1010;
typedef unsigned long long ll;
 
ll Dn[maxn];
ll C[maxn][maxn];
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    Dn[0] = 1, Dn[1] = 0, Dn[2] = 1;
    for(int i = 3; i < maxn; i ++){
        Dn[i] = (ll)(i - 1);
        Dn[i] = (ll)Dn[i]*(Dn[i - 1] + Dn[i - 2]);
    }
 
    for(int i = 0; i < maxn; i ++)
        C[i][0] = C[i][i] = 1;
 
    for(int i = 2; i < maxn; i ++){
        for(int j = 1; j < i; j ++)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
 
 
    int n, k;
    cin >> n >> k;
 
    int u = n - k;
    ll sol = 0;
    for(int i = u; i <= n; i ++)
        sol += (ll)C[n][i]*Dn[n - i];
 
    cout << sol;
}