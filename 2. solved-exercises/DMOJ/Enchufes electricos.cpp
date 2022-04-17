#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 11;
int c[maxn];


int main(){

   int test; cin >> test;
   while(test --) {
       int n; cin >> n;
       int s = 0;
       for(int i = 1; i <= n; i++) {
           cin >> c[i];
            s += c[i];
       }

        // sort(c + 1, c + n + 1);
        s -= (n - 1);
        cout << s << '\n';
   }
}