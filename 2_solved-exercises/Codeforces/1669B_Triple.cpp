#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 2e5 + 1;

int main(){

    int tt;
    cin >> tt;
    while(tt --) {
        int n; cin >> n;
        vector<int> a(n + 1);
        vector<int> cnt(n + 1, 0);
        int ans = -1;
        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
            cnt[ a[i] ] ++;
            if( cnt[a[i]] == 3 ) ans = a[i];
        }
        cout << ans << '\n';
    }
}