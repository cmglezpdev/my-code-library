#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long 
const int maxn = 1e5 + 1;

int main(){

    ll k, n, w;
    cin >> k >> n >> w;

    ll need = k * w * (w + 1LL) / 2LL;
    cout << max(0LL, need - n);
}