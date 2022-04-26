#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 1e5 + 1;
map<int, int> cnt;

int main(){

    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        cnt[ a[i] ] ++;
    } 

    vector<int> v;
    for(auto &i: cnt) {
        for(int j = 0; j < i.second; j ++)
            v.push_back(i.first);
    }

    int query; cin >> query;
    while(query --) {

        int m; cin >> m;
        int idx = upper_bound(v.begin(), v.end(), m) - v.begin();
        idx --;

        if( idx == -1 ) {
            cout << "0\n";
        } else if( m >= v[idx] ){
            cout << idx + 1 << '\n';
        }
    }


}