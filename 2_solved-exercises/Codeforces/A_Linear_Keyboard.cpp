#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int alpha[256];

int main(){

    int tt; cin >> tt;
    while(tt --) {

        fill(alpha, alpha + 256, 0);

        string abc;
        cin >> abc;
        string w; cin >> w;
        for(int i = 0; i < abc.size(); i ++) {
            alpha[ abc[i] ] = i;
        }
            int ans = 0;
        for(int i = 1; i < w.size(); i ++) {
            ans += abs(alpha[ w[i] ] - alpha[ w[i - 1] ]);
        }

        cout << ans << '\n';
    }    


}