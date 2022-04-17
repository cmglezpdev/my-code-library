#include<bits/stdc++.h>

using namespace std;

const int maxn = 2 * 1e5 + 1;
int mark[maxn];
int sol[maxn];


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

   int n; cin >> n;
   int total = 0;
   int last = 0;
    fill(mark, mark + n + 1, -1);

   for(int i = 1; i <= n; i ++) {
       int x; cin >> x;
        if( mark[last] != x) {
            mark[++ last] = x;
            total ++;
        } else {
            mark[last --] = -1;
            total --;
        }
        sol[i] = total;
   }

    for(int i = 1; i <= n; i ++)    
        cout << sol[i] << '\n';

}
