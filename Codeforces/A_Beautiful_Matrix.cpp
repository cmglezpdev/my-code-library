#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int main(){

    int row, col;

   for(int i = 1; i <= 5; i ++) {
       for(int j = 1; j <= 5; j ++) {
           int x; cin >> x;
           if( x == 1 ) {
               row = i;
               col = j;
           }
       }
   }

   cout << abs(row - 3) + abs(col - 3);
}