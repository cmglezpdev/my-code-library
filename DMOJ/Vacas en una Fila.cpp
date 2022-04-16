#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e3 + 1;

int a[maxn];

int main(){

    int n; cin >> n;
    map<int, bool> m;
    
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        m[a[i]] = true;
    } 
    a[0] = -1;
    int maxx = 0;
    for(auto &d : m) {
        int sum = 0;
        int last = 0;
        for(int i = 1; i <= n; i ++) {
            if( a[i] == d.first ) continue;
            if( a[i] == a[last] ) {
                sum ++;
                continue;
            }
            if( a[i] != a[i - 1] ) {
                maxx = max(maxx, sum);
                sum = 1;
                last = i;
                continue;
            }
        }
         maxx = max(maxx, sum);
    }

   

    cout << maxx;

}