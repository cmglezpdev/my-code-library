#include<bits/stdc++.h>

using namespace std;

int main() {

    int test; cin >> test;

    while(test --) {

        string s; cin >> s;
        char x; cin >> x;
        bool ok = false;

        for(int i = 0; i < s.size(); i ++) {
            if( s[i] != x ) continue;

            if( i%2 == 0 && (s.size() - i - 1)%2 == 0 ) {
                ok = true;
                break;
            }
        }


        ( ok ) ? cout << "YES\n" : cout << "NO\n";


    }     




}