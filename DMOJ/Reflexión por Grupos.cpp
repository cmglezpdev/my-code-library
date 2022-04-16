#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int main(){

    while(true) {
        int n; cin >> n;
        if( n == 0 ) break;;

        string s; cin >> s;
        int sz = s.size();
        n = sz / n;
        // string result = "";
        for(int i = 0; i < sz; i += n) {
            reverse( s.begin() + i, s.begin() + i + n );
        }
        cout << s << '\n';
    }
   
}