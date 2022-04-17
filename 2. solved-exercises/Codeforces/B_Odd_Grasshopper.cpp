#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 1e5 + 1;

int main(){


    int tt; cin >> tt;
    while(tt --) {
        ll x, n;
        cin >> x >> n;
        ll ans = x;

        ll a = n/4LL;
        for(int i = 1; i <= n%4; i ++) {
            if( ans%2 == 0 ) ans -= (4LL*a + (ll)i);
            else ans += (4LL * a + (ll)i);    
        }

        cout << ans << '\n';
    }

   
}