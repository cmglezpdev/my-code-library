#include<bits/stdc++.h>

using namespace std;

string s;
string bestSolution = "";

bool isPalindrome(int l, int r, string a) {

    if(l >= r) return true;
    if(a[l] != a[r]) return false;

    return isPalindrome(l + 1, r - 1, a);
}

void Solve( int idx, string a ) {

    if( idx == s.size() ) {
        if( isPalindrome( 0, a.size() - 1, a ) ) {
            bestSolution = max(bestSolution, a);
        }

        return;        
    }

    Solve(idx + 1, a + s[idx]);
    Solve(idx + 1, a);
}


int  main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    Solve(0, "");

    cout << bestSolution << '\n';


}