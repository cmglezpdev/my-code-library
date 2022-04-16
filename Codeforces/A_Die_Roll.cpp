#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int main(){

    int a, b;
    cin >> a >> b;

    int c = 6 - max(a, b) + 1;
    int g = __gcd(c, 6);
    c /= g;
    int t = 6 / g;

    cout << c << '/' << t;
}