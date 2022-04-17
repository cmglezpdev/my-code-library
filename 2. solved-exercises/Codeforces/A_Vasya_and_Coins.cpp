#include<bits/stdc++.h>

using namespace std;


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test; cin >> test;
    while(test --) {
        int uno, dos;
        cin >> uno >> dos;

        if( !uno ) {
            cout << 1 << '\n';
            continue;
        }
        if( !dos ) {
            cout << uno + 1 << '\n';
            continue;
        }

        cout << uno + dos * 2 + 1 << '\n';

    }


}