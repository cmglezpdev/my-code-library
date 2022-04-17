#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int main(){

   string a, b;
   cin >> a >> b;

   for(int i = 0; i < a.size(); i ++) {
       if( 'A' <= a[i] && a[i] <= 'Z' ) 
            a[i] = 'a' + (a[i] - 'A');
   }
    for(int i = 0; i < b.size(); i ++) {
        if( 'A' <= b[i] && b[i] <= 'Z' ) 
            b[i] = 'a' + (b[i] - 'A');
    }

    // cout << a << '\n' << b << '\n';

    if(a == b) {
        cout <<"0";
        return 0;
    }

    int ans = 0;

    for(int i = 0; i < min(a.size(), b.size()); i ++) {
        if( a[i] == b[i] ) continue;
        if( a[i] > b[i] ) {
            ans = 1;
            break;
        } 
        if( a[i] < b[i] ) {
            ans = -1;
            break;
        }
        
    }

    if( ans == 0 ) {
        if( a.size() < b.size() ) {
            cout << -1;
        } else {
            cout << 1;
        }
        return 0;
    }

    cout << ans;

}