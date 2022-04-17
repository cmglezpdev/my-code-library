#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int main(){

    int n, v;
    cin >> n >> v;
    vector<int> ans;
    for(int seller = 1; seller <= n; seller ++) {
        int k; cin >> k;
        bool buy = false;
        for(int i = 1; i <= k; i ++) {
            int p; cin >> p;
            if( v > p && !buy ) buy = true;
        }

        if( buy ) ans.push_back(seller);
    }

    cout << ans.size() << '\n';
    for(auto &s: ans) cout << s << ' ';
   
}