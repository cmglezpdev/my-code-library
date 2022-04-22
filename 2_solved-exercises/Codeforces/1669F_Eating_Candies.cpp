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
        vector<int> a(n + 1);

        for(int i = 1; i <= n; i ++) cin >> a[i];

        if(n == 1) {
            cout << "0\n";
            continue;
        }

        int l = 0, r = n + 1;
        int ls = 0, rs = 0;
        int ans = 0;
        while(l + 1 < r) {

            while( l < r && ((ls == 0 && rs == 0) || ls < rs) ) ls += a[++l];
            while( l < r - 1 && ((ls == 0 && rs == 0) || ls > rs) ) rs += a[--r];

            if( ls == rs ) {
                ans = l + (n - r + 1);
                ls += a[++l];
            } 
        }

        cout << ans << '\n';
    }
}