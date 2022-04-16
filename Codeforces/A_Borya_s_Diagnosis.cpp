#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int main(){

   int n; cin >> n;
   int lastday = 0;
    for(int i = 1; i <= n; i ++) {
       int s, d;
       cin >> s >> d;
        if( s > lastday ) {
            lastday = s;
            continue;
        }
        
        int x = (lastday - s) / d;
        for(int j = x; ; j ++) {
            if( s + j*d > lastday ) {
                lastday = s + j * d;
                break;
            }
        }
    }    

    cout << lastday;
}