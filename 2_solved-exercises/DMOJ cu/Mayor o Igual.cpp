#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 1e5 + 1;

int main(){

    int n, k; 
    cin >> n >> k;
    vector<int> v;   
    for(int i = 0; i < n; i ++) {
        int x; cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    k --;
    if( k == n - 1 ) {
        cout << 1000000000;
        return 0;
    }

    if( v[k] == v[k + 1] ) {
        cout << -1;
        return 0;
    }

    cout << v[k + 1] - 1;

}