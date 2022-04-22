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
        int n; cin >> n;
        int oddp = 0, oddi = 0, evenp = 0, eveni = 0;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
            if( i%2 == 0 ) {
                if( a[i]%2 == 0 ) evenp ++;
                else eveni ++;
            } else {
                if( a[i]%2 == 0 ) oddp ++;
                else oddi ++;
            }
        }
        // cout << oddp << ' ' << oddi << ' ' << evenp << ' ' << eveni << '\n';

        if( (oddp != 0 && oddi != 0) || (evenp != 0 && eveni != 0) ) {
            cout << "NO\n";
            continue;
        }

        if( (oddp == 0 || oddi == 0) && (evenp == 0 || eveni == 0) ) {
            cout << "YES\n";
            continue;
        }


    }

}