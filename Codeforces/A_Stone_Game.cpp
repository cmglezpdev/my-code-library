#include<bits/stdc++.h>

using namespace std;

const int maxn = 101;
int a[maxn];

int minx(int x, int y, int z) {
    return min( x, min(y, z) );
}

int main() {

    int test; cin >> test;
    while(test --) {

        int n; cin >> n;
        int mx = -(1<<30), mn = (1<<30);
        int imx = 0, imn = 0;

        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
            if( a[i] > mx ) {
                mx = a[i];
                imx = i;
            }
            if( a[i] < mn ) {
                mn = a[i];
                imn = i;
            }
        }

        if( imx < imn ) swap(imx, imn);

        int sol = minx( imx, n - imn + 1, imn + (n - imx + 1) );

        cout << sol << '\n';
    }



}