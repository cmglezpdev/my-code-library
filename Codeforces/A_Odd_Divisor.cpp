#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long


int main(){

    FAST

    int tt; cin >> tt;
    while(tt --) {
        ll n; cin >> n;
        ( (n&(n - 1ll)) == 0 ) ? cout << "NO\n" : cout << "YES\n";
    }


}