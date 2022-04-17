#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int main(){

   int n, k;
   cin >> n >> k;
   int part[n + 1];
   
   for(int i = 1; i <= n; i ++) cin >> part[i];
    int ans = 0;
    for(int i = 1; i <= n; i ++)
        if( part[i] >= part[k] && part[i] > 0 ) ans ++;

    cout << ans; 
}