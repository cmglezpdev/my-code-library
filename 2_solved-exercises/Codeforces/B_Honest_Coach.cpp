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
        vector<int> v;
        for(int i = 0; i < n; i ++) {
            int c; cin >> c;
            v.push_back(c);
        }
    
        sort(v.begin(), v.end());
        int ans = (1<<30);
        for(int i = 1; i < n; i ++) {
            ans = min(ans, v[i] - v[i - 1]);
        }

        cout << ans << '\n';
    }


}
