#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 51;
int n, m;
int mapa[maxn][maxn];

int movx[] = {0, 0, 1, -1, 1, -1, -1, 1};
int movy[] = {1, -1, 0, 0, 1, 1, -1, -1};

bool can(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m && mapa[x][y]);
}

bool is(int x, int y, int d) {
    for(int k = 0; k < 8; k ++) {
        int dx = x + movx[k];
        int dy = y + movy[k];

        if( can(dx, dy) && mapa[dx][dy] == d )
            return true;
    }

    return false;
}

int main(){
 
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> mapa[i][j];
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if( mapa[i][j] == 0 ) continue;
            bool isOk = is(i, j, mapa[i][j]);
            if( isOk )
                ans = max(ans, mapa[i][j]);
        }
    }

    cout << ans;
}