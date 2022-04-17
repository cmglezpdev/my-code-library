#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1000;

int valdes[maxn];


int main(){

   int n; cin >> n;
   for(int i = 0; i < n; i ++) {
       int x, y, z;
       cin >> x >> y >> z;
       for(int j = x; j <= y; j ++) valdes[j] += z;   
   }

    int ans = 0;
    for(int i = 0; i < maxn; i ++)
        ans = max(ans, valdes[i]);

    cout << ans;
}