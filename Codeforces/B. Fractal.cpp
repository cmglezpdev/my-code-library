//* https://codeforces.com/contest/36/problem/B
#include<bits/stdc++.h>

using namespace std;

const int maxn = 250;
char board[maxn][maxn];
char Template[5][5];

void PaintPartition(int left, int right, int top, int bottom) {
    for(int i = top; i <= bottom; i ++) {
        for(int j = left; j <= right; j ++) {
            board[i][j] = '*';
        }
    }
}

int Pow(int n, int e) {
    int ret = 1;
    for(int i = 1; i <= e; i ++)
        ret = (1LL * ret * n);
    return ret;
}


void BuildFractal( int n, int step, int left, int right, int top, int bottom ) {

    if(step == 0) {
        return;
    }


    int div1 = left + (right - left + 1) / n - 1; // division horizontal
    int div2 = top + (bottom - top + 1) / n - 1; // division vertical

    // Indices para el primer pedaso
    left = left;
    right = div1;
    top = top;
    bottom = div2;
    
    int middle = Pow(n, step - 1);

    // Pinar las partes que nos piden segun el template
    // y dividir las que no
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            int despx = middle * (j - 1);
            int despy = middle * (i - 1);

            if(Template[i][j] == '*') {
                // Pinar esta particion
                PaintPartition(left + despx, right + despx, top + despy, bottom + despy);
                continue;
            }

            // Dividir esta particion fractalmente
            BuildFractal(n, step - 1, left + despx, right + despx, top + despy, bottom + despy);
            
        }
    }
}


int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n, k;
    cin >> n >> k;
    int len = Pow(n, k);

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            cin >> Template[i][j];
        }
    }


    for(int i = 1; i <= len; i ++) {
        for(int j = 1; j <= len; j ++) {
            board[i][j] = '.';
        }
    }

    BuildFractal(n, k, 1, len, 1, len);

    for(int i = 1; i <= len; i ++) {
        for(int j = 1; j <= len; j ++) {
            cout << board[i][j];
        }
        cout << endl;
    }

}