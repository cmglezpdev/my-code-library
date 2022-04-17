#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;
int cnt[4];

int main(){

   string op; cin >> op;

   for(int i = 0; i < op.size(); i ++) {
       if( '1' <= op[i] && op[i] <= '3' ) {
           cnt[ (int)(op[i] - '0') ] ++;
       }
   }

    int cntop = cnt[1] + cnt[2] + cnt[3] - 1;

   for(int i = 1; i <= 3; i ++) {
       while( cnt[i] -- ) {
           cout << i;
           if( cntop ) {
                cout << "+";
                cntop --;
           }
           
       }
   }
}