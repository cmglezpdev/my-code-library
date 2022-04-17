#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int main(){

   double x, y;
   cin >> x >> y;
   if(x == 0 && y == 0) {
       cout << "Origem";
   } else
   if(x == 0) {
       cout << "Eixo Y";
   } else
   if(y == 0) {
       cout << "Eixo X";
   } else
   if( x > 0 && y > 0 ) 
        cout << "Q1";
    else if(x < 0 && y > 0)
        cout << "Q2";
    else if(x < 0 && y < 0)
        cout << "Q3";
    else cout << "Q4";
}