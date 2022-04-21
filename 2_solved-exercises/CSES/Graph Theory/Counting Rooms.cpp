#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 1e3 + 1;
int n, m;
char room[maxn][maxn];
bool visited[maxn][maxn];

int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, 1, -1};

bool can(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

void dfs(int x, int y) {
    visited[x][y] = true;

    for(int k = 0; k < 4; k ++) {
        int dx = x + mx[k];
        int dy = y + my[k];
        if( !can(dx, dy) || visited[dx][dy] || room[dx][dy] == '#' ) continue;
        dfs(dx, dy);
    }
}


int main(){

    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> room[i][j];
        }
    }

    int r = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if( visited[i][j] || room[i][j] == '#' ) continue;
            r ++;
            dfs(i, j);
        }
    }

    cout << r;
}