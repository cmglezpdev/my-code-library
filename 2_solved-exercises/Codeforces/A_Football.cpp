#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int main(){

   string a; cin >> a;

    if( a.size() < 7 ) {
        cout << "NO";
        return 0;
    }

   string one = "1111111";
   string zero = "0000000";

    for(int i = 0; i + 7 <= a.size(); i ++) {
        string c = a.substr(i, 7);
        if( c == one || c == zero ) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

}