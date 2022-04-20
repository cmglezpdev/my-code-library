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
        int n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for(int i = 0; i < n; i ++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end(), greater<int> ());

        ll sum = a[0] + a[0] + 1;
        for(int i = 1; i < n; i ++) {
            sum += a[i] + 1;
            if( i == n - 1 ) sum -= a[i];
            if( sum > m ) break;
        }

        if( sum <= m ) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }
   
}