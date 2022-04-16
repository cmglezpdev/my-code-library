#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define db double

const int maxn = 1e5 + 1;

int main(){

    db n; cin >> n;
    if( n < 0.00 || n > 100.00 ) {
         cout << "Out of Intervals";   
    } else {

        if( n >= 0.00 && n <= 25.00 ) {
            cout << "Interval [0,25]";
        } else
        if( n > 25.00 && n <= 50.00 ) {
            cout << "Interval (25,50]";
        } else
        if( n > 50.00 && n <= 75.00 ) {
            cout << "Interval (50,75]";
        }
        else
        cout << "Interval (75,100]";

    }


}