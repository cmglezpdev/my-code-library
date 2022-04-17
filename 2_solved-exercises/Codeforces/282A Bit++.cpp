#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int main(){

   int n; cin >> n;
   int ans = 0;
   while(n --) {
       string oper; cin >> oper;
        if( oper == "X++" || oper == "++X" ) ans ++;
        if( oper == "X--" || oper == "--X" ) ans --;
   }

   cout << ans;
}