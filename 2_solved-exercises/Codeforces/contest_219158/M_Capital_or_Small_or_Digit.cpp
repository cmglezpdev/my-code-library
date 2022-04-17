#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int main(){

   char x; cin >> x;
   if( x >= '0' && x <= '9' ) 
     cout << "IS DIGIT";
    else {
        cout << "ALPHA\n";
        if( x >= 'a' && x <= 'z' )
            cout << "IS SMALL";
        else    cout << "IS CAPITAL";
    }
}