#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 105;
bool mapa[maxn][maxn];

const int movx[4] = {1, -1, 0, 0};
const int movy[4] = {0, 0, 1, -1};

int n, m;
bool mk[maxn][maxn];

bool canMov(int x, int y) {
    return(x > 0 && x <= n && y > 0 && y <= m);
}


int dfs(int x, int y) {

    mk[x][y] = true;

    int length = 1;

    for(int k = 0; k < 4; k ++) {
        int dx = x + movx[k];
        int dy = y + movy[k];

        if(canMov(dx, dy) && !mk[dx][dy] && mapa[dx][dy])
            length += dfs(dx, dy);
    }

    return length;
}



int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++) {
            mapa[i][j] = mk[i][j] = false;
        }


    int k;
    cin >> n >> m >> k;
    vector< pair<int, int> > v;

    for(int i = 0; i < k; i ++) {

        int x, y;
        cin >> x >> y;
        mapa[x][y] = true;
        v.push_back({x, y});
    }

    int maxLen = 0;

    for(auto i : v) {
        if(mk[i.first][i.second]) continue;
        maxLen = max(maxLen, dfs(i.first, i.second));
    }

    cout << maxLen;
}