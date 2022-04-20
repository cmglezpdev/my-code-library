#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long
const int maxn = 1e5 + 1;

int main(){


    int tt; cin >> tt;
    while(tt -- ) {
        ll n, m;
        cin >> n >> m;

        if(n > m) swap(n, m);

        if( n == 1 && m == 1 ) {
            cout << "0\n";
        } else 
        if( min(n, m) == 1 ) {
            if( max(n, m) == 2 ) {
                cout << "1\n";
            } else {
                cout << "-1\n";
            }
        } else {

            ll ans = 2LL * (n - 1) + 2LL * (m - n - 1) + ((m - n - 1)%2 == 0 ? 1LL : 2LL );

            cout << ans << '\n';

        }

    
    }

}