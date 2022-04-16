#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;
map<int, int> cnt;

int main(){

    FAST

    int ts; cin >> ts;
    while(ts -- ){
        int n; cin >> n;
        cnt.clear();
        
        int maxcnt = 0;

        for(int i = 0; i < n; i ++) {
            int x; cin >> x;
            cnt[x] ++;
            maxcnt = max(maxcnt, cnt[x]);
        }
        int ans = 0;
        while(maxcnt < n) {
            ans ++; // new copy
            int aux = min( maxcnt, n - maxcnt ); // swap items
            ans += aux;
            maxcnt += aux;
            
        }   


        cout << ans << '\n';

    }    
}   