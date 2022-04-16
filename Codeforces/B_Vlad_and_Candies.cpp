#include<bits/stdc++.h>

using namespace std;

const int maxn = 2 * 1e5 + 1;
int a[maxn];

int main() {
    
    int test; cin >> test;
    while(test --) {

        // fill(a, a + maxn, 0);

        int n; cin >> n;
        int mini = 1e9;
        for(int i = 0; i < n; i ++) {
            cin >> a[i];
            int mini = min(mini, a[i]);
        }

        sort( a, a + n );
        int acum = 0;
        for(int i = 0; i < n; i ++) {
            a[i] -= acum;
            acum += a[i];
        }

        if( a[n - 1] <= 1 )
            cout << "YES\n";
        else    cout << "NO\n";


    }

}