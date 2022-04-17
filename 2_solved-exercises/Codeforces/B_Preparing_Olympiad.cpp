#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 16;
int c[maxn];

int main(){

    FAST

    int n, l, r, x;
    cin >> n >> l >> r >> x;
    for(int i = 0; i < n; i ++)
        cin >> c[i];

    int ans = 0;
    for(int i = 1; i < (1<<n); i ++) {
        int minc = (1<<30), maxc = -(1<<30), diff = 0;
        for(int j = 0; j < n; j ++) {
            if( i&(1<<j) ) {
                diff += c[j];
                minc = min(minc, c[j]);
                maxc = max(maxc, c[j]);
            }
        }
        if( l <= diff && diff <= r && (maxc - minc) >= x ) ans ++;
    }

    cout << ans;
}