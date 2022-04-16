#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

bool isLuckyNumber(int x) {
    while(x) {
        int d = x%10;
        if( d != 4 && d != 7 ) {
            return false;
        }

        x /= 10;
    }
    return true;
}

int main(){

    int n; cin >> n;

    if( isLuckyNumber(n) ) {
        cout << "YES\n";
        return 0;
    }

    for(int i = 4; i < n; i ++) {
        if( !isLuckyNumber(i) ) continue;
        if( n%i  == 0 ) {
            cout << "YES\n";
            return 0;
        }  
    }

    cout << "NO\n";

}