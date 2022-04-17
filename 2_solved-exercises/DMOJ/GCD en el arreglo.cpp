#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 1;
int a[maxn];


int main(){

    // cout << __gcd(2000000000, 2000000000) << '\n';

   ios_base::sync_with_stdio(0);
   cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    int Ggcd = 1;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if( i == 1 ) Ggcd = a[i];
        Ggcd = __gcd( Ggcd, a[i] );
    }

    // cout << Ggcd << '\n';

    while(m --){
        int pos, upd;
        cin >> pos >> upd;
        a[pos] /= upd;

        Ggcd = __gcd( Ggcd, a[pos] );
        cout << Ggcd << '\n';
    }

}