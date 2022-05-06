#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 1e5 + 1;

bool seen[maxn];

int two(int n) {
    int l = floor(log10(n)) + 1;
    if( l == 1 ) return 0;
    if(l == 2) return n/10;
    if(l == 3) return (n/10);
    return (n/10)%100;
}

int main(){

    int n; cin >> n;
    int ans = 0;
    while( !seen[n] ) {
        seen[n] = true;
        ans ++;
        int center = two(n);
        // cout << center << ' ';
        center *= center;
        n = center;
    } 

    cout << ans;
}