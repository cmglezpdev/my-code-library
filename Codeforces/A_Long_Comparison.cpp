#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int len(int n){
    return floor(log10(n)) + 1;
}

int digit(int n, int idx) {
    int l = len(n);
    if( idx > l ) return 0;
    int p = pow(10, l - idx);
    n /= p;
    return n%10;
}

int main(){

    FAST

    int tt; cin >> tt;
    while(tt --) {
        int a, pa, b, pb;
        cin >> a >> pa >> b >> pb;

        if(a == b && pa == pb) {
            cout << "=\n";
        } else
        if(len(a) + pa < len(b) + pb) {
            cout << "<\n";
        }else
        if(len(a) + pa > len(b) + pb) {
            cout << ">\n";
        } else
        if( a == b ) { 
            if( pa < pb ) cout << "<\n";
            else cout << ">\n";
        }else
        if( pa == pb ) {
            if( a < b ) cout << "<\n";
            else cout << ">\n";
        } else 
        if( len(a) + pa == len(b) + pb ){
            int l = len(a) + pa;
            int equil = 0;
            for(int i = 1; i <= max(len(a), len(b)); i ++) {
                if(digit(a, i) == digit(b, i)) continue;
                if( digit(a, i) > digit(b, i) )
                    equil = 1;
                else equil = -1;
                break;
            }
            if( equil == 0 ) cout << "=\n";
            else if(equil == -1) cout << "<\n";
            else cout << ">\n";
        }
    
    }
}