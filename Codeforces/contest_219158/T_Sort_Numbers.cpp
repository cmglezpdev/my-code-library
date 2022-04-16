#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int main(){

   int n[3];
   cin >> n[0] >> n[1] >> n[2];
    int o[3];
    o[0] = n[0];
    o[1] = n[1];
    o[2] = n[2];

    sort(o, o + 3);
    cout << o[0] << '\n';
    cout << o[1] << '\n';
    cout << o[2] << '\n';
    cout << '\n';
    cout << n[0] << '\n';
    cout << n[1] << '\n';
    cout << n[2] << '\n';
    cout << '\n';
}