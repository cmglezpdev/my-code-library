#include<bits/stdc++.h>

using namespace std;

bool male( char x ) {
    return x == '0';
}
bool female( char x ) {
    return x == '1';
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int test; cin >> test;
    while (test --)
    {
        int n; cin >> n;
        string row; cin >> row;

        int cnt = 0;
        int muj = 0, hom = 0;
        for(int i = 1; i < n; i ++) {
            if( male( row[i - 1] ) && male(row[i]) ) cnt += 2;
            else

            if( female(row[i]) && male(row[i - 1]) && i + 1 < n && male(row[i + 1]) ) cnt ++;


        }

        cout << cnt << '\n';
    }



}