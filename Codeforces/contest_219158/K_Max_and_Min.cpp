#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int max(int a, int b, int c) {
    return max(a, max(b, c));
}

int min(int a, int b, int c) {
    return min(a, min(b, c));
}

int main(){
    int a, b, c;
    cin >> a>> b >> c;

    cout << min(a, b, c) << ' ' << max(a, b, c);
   
}