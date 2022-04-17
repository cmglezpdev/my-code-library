#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int main(){

   int ts;
   cin >> ts;
   while(ts --) {
       string s; cin >> s;
       bool prev[30];
       fill(prev, prev + 30, false);
        int m = 0;
        for(int i = 0; i < s.size(); i ++ ) {
            int c = (int)(s[i] - 'a');
            if( !prev[c] ) {
                prev[c] = true;
                continue;
            } 
            
            m += 2;
            fill(prev, prev + 30, false);
        }    
        int ans = s.size() - m;
        cout << ans << '\n';
   }
}