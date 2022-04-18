#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int Phi(int n) {
    int phi = n;
    for(int i = 2; i*i <= n; i ++) {
        if( n%i == 0 ) {
            while(n%i == 0) n /= i;
            phi -= phi / i;
        }
    }
    if(n > 1) phi -= phi / n;
    return phi;
}

int main(){

    int tt; cin >> tt;
    while(tt --) {
        int n; cin >> n;
        cout << Phi(n) << '\n';
    }

}