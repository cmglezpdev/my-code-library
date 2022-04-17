#include<bits/stdc++.h>

using namespace std;

vector<string> perm;


void GenerateCombinations( string s ) {

    if(s.size() == 3) {
        perm.push_back( s );
        return;
    }

    GenerateCombinations(s + '0');

    GenerateCombinations(s + '1');
}


bool isBalance(string s, char A, char B, char C) {

    int acum = 0;
    for(int i = 0; i < s.size(); i ++) {
        if( s[i] == 'A' ) acum += ( A == '(' ) ? 1 : -1;
        if( s[i] == 'B' ) acum += ( B == '(' ) ? 1 : -1;
        if( s[i] == 'C' ) acum += ( C == '(' ) ? 1 : -1;
    
        if( acum < 0 ) return false;
    }

    return (acum == 0);
}


int main() {


    GenerateCombinations("");

    // for(auto &i : perm)
    //     cout << i << "\n";

    int test; cin >> test;

    while(test --) {

        string s; cin >> s;
        bool ok = false;

        for(auto &i : perm) {
            char A = (i[0] == '1') ? '(' : ')';
            char B = (i[1] == '1') ? '(' : ')';
            char C = (i[2] == '1') ? '(' : ')';

             ok = isBalance(s, A, B, C);
            if(ok) break;
        }

        if( ok )
            cout << "YES\n";
        else cout << "NO\n";

    }


}