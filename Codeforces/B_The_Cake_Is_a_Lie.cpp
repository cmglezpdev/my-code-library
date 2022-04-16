#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);


int main(){

    FAST

    int test; cin >> test;
    while(test --) {
        int n, m, k;
        cin >> n >> m >> k;

        if( n*m - 1 == k)
            cout << "YES\n";
        else cout  << "NO\n";

    }
}