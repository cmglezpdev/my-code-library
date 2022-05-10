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
        vector<int> v(n);
        for(int i = 0; i < n; i ++) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());
        int ans = 0;
        if( v[0] == 0 ) {
            ans = n - 1;
            for(int i = 1; i < n && !v[i]; i ++, ans --);        
        } else {

            bool ok = false;
            for(int i = 1; i < n; i ++) {
                if( v[i] == v[i - 1] ) {
                    ok = true;
                    break;
                }
            }   

            if( ok ) ans = n;
            else ans = n + 1;

        }

        cout << ans << '\n';
    }
}