#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int main(){

    int n; cin >> n;

    long long Vcola = 0;
    int cans[n + 1];
    for(int i = 1; i <= n; i ++) {
        long long vc;
        cin >> vc;
        Vcola += vc;
    }
    for(int i = 1; i <= n; i ++) {
        cin >> cans[i];
    }

    sort( cans + 1, cans + 1 + n, greater<int>() );

   if( cans[1] + cans[2] >= Vcola ) {
       cout << "YES";
   }
   else cout << "NO";


}