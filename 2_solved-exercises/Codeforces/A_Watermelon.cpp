#include<bits/stdc++.h>
 
using namespace std;



int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    int n; cin >> n;
    for(int i = 2; i < n; i += 2) {
        if( n-i > 0 && (n - i)%2 == 0 ) {
            cout << "YES\n";
            return 0;
        }
    }   

    cout << "NO\n";

 
}