#include<bits/stdc++.h>

using namespace std;

const int maxn = 55;
bool selection[maxn];
map< pair<int, int>, bool > mapa;
int xSol, ySol;

void Combinatoria( int idx, int n, int cant, int num[] ) {

    if( idx == n + 1 && cant != 2 )
        return;
    
    if( cant == 2 ) {
        if( mapa[ make_pair(num[0], num[1]) ] || mapa[ make_pair(num[1], num[0]) ] )
            return;
        xSol = num[0], ySol = num[1];
        return;
    }       

    selection[idx] = true;
    num[cant] = idx;
    Combinatoria( idx + 1, n, cant + 1, num );

    selection[idx] = false;
    num[cant] = 0;
    Combinatoria( idx + 1, n, cant, num );

}



int main() {

    int n;
    cin >> n;

    for(int i = 1; i <= n * (n - 1) / 2; i ++) {
        int x, y;
        cin >> x >> y;
        mapa[ make_pair(x, y) ] = true;
    }
    int num[2];
    Combinatoria(1, n, 0, num);

    for(int i = 1; i <= n; i ++) {
        if( i == xSol || i == ySol )
            continue;

        if( mapa[ make_pair(xSol, i) ] && mapa[ make_pair(i, ySol) ] ) {
            break;
        }

        if( mapa[ make_pair(ySol, i) ] && mapa[make_pair(i, xSol)] ) {
            swap(xSol, ySol);
            break;
        }
    }



    cout << xSol << ' ' << ySol << '\n';

}


// 1 6

// 2 1
// 2 5
// 2 6
// 2 7

// 3 1
// 3 2
// 3 5
// 3 6
// 3 7

// 4 1
// 4 2
// 4 3
// 4 5
// 4 6
// 4 7
// 4 8
// 4 9

// 5 1
// 5 6
// 5 7

// 7 1
// 7 6

// 8 1
// 8 2
// 8 5
// 8 6
// 8 7
// 8 9

// 9 1
// 9 2
// 9 3
// 9 5
// 9 6
// 9 7