#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 60;
char c[maxn][maxn];


bool isPista(int x, int y, int n, int m) {
    // Pista Horizontal
    if( (y - 1 == 0 || c[x][y - 1] == '#') && y + 2 <= m && c[x][y + 1] == '.' && c[x][y + 2] == '.' )    return true;
    if( (x - 1 == 0 || c[x - 1][y] == '#') && x + 2 <= n && c[x + 1][y] == '.' && c[x + 2][y] == '.' ) return true;

    return false;
}


int main(){

    FAST
   
   int n, m;
   cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> c[i][j];
        }
    }
    vector<pair<int, int> > ans;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if( c[i][j] == '.' && isPista(i, j, n, m) )
                ans.push_back(make_pair(i, j));
        }
    }


    cout << ans.size() << '\n';
    for(auto i: ans) {
        cout << i.first << ' ' << i.second << '\n';
    }


}
