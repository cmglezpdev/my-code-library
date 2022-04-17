#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int main(){

   string a; cin >> a;

   if( 'a' <= a[0] && a[0] <= 'z' )
        a[0] = (char)('A' + (a[0] - 'a'));

    cout << a;
}