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
        string s; cin >> s;
        vector<int> seg;
        int acum = 1;
        for(int i = 1; i < n; i ++) {
            if( s[i] == s[i - 1] ) acum ++;
            else {
                seg.push_back(acum);
                acum = 1;
            }
        }
        seg.push_back(acum);
    
        n = seg.size();
        int ans = 0;
        for(int i = 0; i < n - 1; i ++) {
            if( seg[i]%2 != 0 ) {
                seg[i] --;
                seg[i + 1] ++; 
                ans ++;
            }
        }
    
        cout << ans << '\n';
    }
}