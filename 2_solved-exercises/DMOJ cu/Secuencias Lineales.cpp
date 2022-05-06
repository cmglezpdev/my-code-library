#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 1e5 + 1;

int main(){

    int n; cin >> n;
    vector<int> v(n);
    vector<bool> cnt(101, 0);

    for(int i = 0; i < n; i ++ ) {
        cin >> v[i];
        cnt[ v[i] ] = true; 
    }

    n --;
    int ans = 0;
    for(int i = 0; i <= n - 2; i ++ ) {
        for(int j = i + 1; j <= n - 1; j ++) {
            int diff = v[j] - v[i];
            if( v[j] + diff <= 100 && cnt[ v[j] + diff ] ) {
                ans ++;
            }
        }
    }

    cout << ans;

}