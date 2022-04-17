#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int main(){

   float n; cin >> n;
   
   int i = (int)n;
    float f = (float)(n - (float)i);

    if( f == 0.00 ) {
        cout << "int " << i;
    } else {
        cout << "float " <<i << ' ' << f;
    }
}