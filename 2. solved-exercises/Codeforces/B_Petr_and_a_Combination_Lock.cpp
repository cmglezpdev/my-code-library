#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 16;
int angle[maxn];


int main(){
    
    FAST

    int n; cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> angle[i];

    for(int mask = 0; mask < (1<<n); mask ++) {
        int c = 0;
        for(int i = 0; i < n; i ++) {
            if( mask&(1<<i) ) c = (c + angle[i])%360;
            else c = (c - angle[i])%360;
        }
        if( c == 0 ) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}