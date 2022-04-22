#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 1e5 + 1;

int main(){

    int tt; cin >> tt; 
    while(tt --) {
        int rating; cin >> rating;
        
        if( rating <= 1399 ) {
            cout << "Division 4\n";
        } else
        if( 1400 <= rating && rating <= 1599 ) {
            cout << "Division 3\n";
        } else 

        if( 166 <= rating && rating <= 1899 ) {
            cout << "Division 2\n";
        } else
        cout << "Division 1\n";
    }
}