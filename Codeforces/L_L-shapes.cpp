//! FIX
#include<bits/stdc++.h>

using namespace std;

const int maxn = 2050;
char board[maxn][maxn];
int n;

char letters[] = {'A', 'B', 'C'};

bool IsABC( char x ) {
    return ( x == 'A' || x == 'B' || x == 'C' );
}

char PaintWith( int x, int y ) {

    int let[] = {0, 0, 0};
    
    if( IsABC(board[x][y]) ) let[ board[x][y] - 'A' ] ++;
    if( IsABC(board[x + 1][y]) ) let[ board[x + 1][y] - 'A' ] ++;
    if( IsABC(board[x][y + 1]) ) let[ board[x][y + 1] - 'A' ] ++;
    if( IsABC(board[x + 1][y + 1]) ) let[ board[x + 1][y + 1] - 'A' ] ++;

    // left - top
    if( x - 1 >= 1 && IsABC(board[x - 1][y]) ) let[ board[x - 1][y] - 'A' ] ++; // top
    if( y - 1 >= 1 && IsABC(board[x][y - 1]) ) let[ board[x][y - 1] - 'A' ] ++; // left

    y ++;
    // right - top
    if( x - 1 >= 1 && IsABC(board[x - 1][y]) ) let[ board[x - 1][y] - 'A' ] ++; // top
    if( y + 1 <= n && IsABC(board[x][y + 1]) ) let[ board[x][y + 1] - 'A' ] ++; // right

    
    x ++; y --;
    // left - buttom
    if( x + 1 <= n && IsABC(board[x + 1][y]) ) let[ board[x + 1][y] - 'A' ] ++; // buttom
    if( y - 1 >= 1 && IsABC(board[x][y - 1]) ) let[ board[x][y - 1] - 'A' ] ++; // left

    y ++;
    // right - buttom
    if( x + 1 <= n && IsABC(board[x + 1][y]) ) let[ board[x + 1][y] - 'A' ] ++; // buttom
    if( y + 1 <= n && IsABC(board[x][y + 1]) ) let[ board[x][y + 1] - 'A' ] ++; // right

    if( let[0] == 0 ) return 'A'; 
    if( let[1] == 0 ) return 'B';
    return 'C'; 

}


int cuadrante(int pa, int pb, int la, int lb) {
    if( la <= pa && lb <= pb ) return 2;
    if( la <= pa && lb > pb ) return 1;
    if( la > pa && lb > pb ) return 4;
    return 3;
}


void PaintBoard(int a, int b, int c, int d, int la, int lb) {
    
    if( a == b && c == d ) return;

    int mv = (a + b) >> 1; // medio vertical
    int mh = (c + d) >> 1; // medio horizontal

    int cuad = cuadrante(mv, mh, la, lb);
    char paint = PaintWith(mv, mh);

    if( cuad != 1 ) board[mv][mh + 1] = paint;
    if( cuad != 2 ) board[mv][mh] = paint;
    if( cuad != 3 ) board[mv + 1][mh] = paint; 
    if( cuad != 4 ) board[mv + 1][mh + 1] = paint; 

    int px = 0, py = 0;
    // Cuadrante 2
    if( cuad == 2 ) {px = la; py = lb;} else {px = mv; py = mh;}
    PaintBoard(a, mv, c, mh, px, py);
    // Cuadrante 1
    if( cuad == 1 ) {px = la; py = lb;} else {px = mv; py = mh + 1;}
    PaintBoard(a, mv, mh + 1, d, px, py);
    // Cuadrante 4
    if( cuad == 4 ) {px = la; py = lb;} else {px = mv + 1; py = mh + 1;}
    PaintBoard(mv + 1, b, mh + 1, d, px, py);
    // Cuadrante 3
    if( cuad == 3 ) {px = la; py = lb;} else {px = mv + 1; py = mh;}
    PaintBoard(mv + 1, b, c, mh, px, py);



}



int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    cin >> n >> x >> y;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            board[i][j] = '-';
        }
    }

    board[x][y] = '.';
    PaintBoard(1, n, 1, n, x, y);

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            cout << board[i][j];
        }
        cout << '\n';
    }



}

