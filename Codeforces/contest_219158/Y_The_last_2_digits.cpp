#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int mult(int a, int b) {

    int la = a%10;
    int lb = b%100;

    int ans = (la * lb)%100;
    return ans;
}


int main(){

   int a, b, c, d;
   cin >> a >> b >> c >> d;

    int ans = mult(a, b);
        ans = mult(ans, c);
        ans = mult(ans, d);
        
    if( ans < 10 ) cout << "0" << ans << '\n';
    else cout<< ans;
}