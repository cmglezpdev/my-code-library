#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long


int main(){

    int tt; cin >> tt;
    while(tt --) {
        int n; cin >> n;
        int c = 0;
        for(int i = 1; i <= n; i ++) {
            int x; cin >> x;
            c += (x - 1);
        }

        ( c%2 == 0 ) ? cout << "maomao90\n" : cout << "errorgorn\n";
    }
}