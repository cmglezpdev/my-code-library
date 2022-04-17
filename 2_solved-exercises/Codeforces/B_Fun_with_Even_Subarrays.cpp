#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int main(){

    int tt; cin >> tt;
    while(tt --) {
        
        int n; cin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
        }

        int cnt = 0;
        for(int i = 1; i <= n; i ++) cnt += (a[i] == a[n]);

        if(  cnt == n ) {
            cout << "0\n";
            continue;
        }
        int filler = a[n];
        int ans = 0;
        for(int i = n; i >= 1; i --) {
            if( a[i] == filler ) continue;
            ans ++; i ++;
            // Se marcan  (n - i) posisiones hacia atras
            i = (n - 2 * (n - i + 1)) + 1;
        }

        cout << ans << '\n';        

    }    
}