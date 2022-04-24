#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

int main(){

    FAST

    int tt; cin >> tt;
    while(tt --) {
      
        int n, k; cin >> n >> k;
        vector<int> a(n); 
        for(int i = 0; i < n; i ++) {
            cin >> a[i];
        }

        int p = 30;
        while(k >= n && p >= 0) {
            int c = 0;
            for(int i = 0; i < n; i ++) {
                if( a[i]&(1<<p) ) {
                    c ++;
                    continue;
                }
                a[i] |= (1<<p);
            }

            k -= (n - c);
            p --;
        }

        int ans = 0;
        if( k == 0 ) {
            ans = a[0];
            for(int i = 1; i < n; i ++) 
                ans &= a[i];

            cout << ans << '\n';
        } else {

            for( ; p >= 0 && k > 0; p --) {
                int c = 0;
                for(int i = 0; i < n; i ++) 
                    if( (a[i]&(1<<p)) == 0 ) c ++;
                
                if( c <= k ) {
                    k -= c;
                    for(int i = 0; i < n; i ++) 
                        a[i] |= (1<<p);
                }
            }
        
            ans = a[0];
            for(int i = 1; i < n; i ++)
                ans &= a[i];
            cout << ans << '\n';
        }





    }



}