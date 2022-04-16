#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 1e5 + 1;

int main(){

   ll n, m, a;
   cin >> n >> m >> a;

    ll x = ( n % a == 0 ) ? n / a : n / a + 1LL;
    ll y = ( m % a == 0 ) ? m / a : m / a + 1LL;

    cout << x * y;
}