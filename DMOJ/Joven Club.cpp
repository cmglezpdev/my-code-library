#include<bits/stdc++.h>

using namespace std;

map <int, vector<int> > rocasX;
map <int, vector<int> > rocasY;
map< pair<int, int>, bool > mark;

const int inf = 2 * 1e9;

int Solve( int x, int y, int endx, int endy ) {

    if( x == endx && y == endy )
        return 1;

    if( rocasX.find(x) == rocasX.end() && rocasY.find(y) == rocasY.end() ) {
        return inf;
    }

    int pasos = inf;

    if( rocasY.find(y) != rocasX.end() ) {
        for(int i = 0; i < rocasY[y].size(); i ++) {
            // Si ya choque con esa roca
            if( mark[ { rocasY[y][i], y } ] ) continue;
            // Si es uno del costado
            if( rocasY[y][i] - 1 == x || rocasY[y][i] + 1 == x) continue;

            mark[ { rocasY[y][i], y } ] = true;
            pasos = min(pasos, Solve(rocasY[y][i] < x ? rocasY[y][i] + 1 : rocasY[y][i] - 1, y, endx, endy) );
            mark[ { rocasY[y][i], y } ] = false; 
        }
    }

    if( rocasX.find(x) != rocasY.end() ) {
        for(int i = 0; i < rocasX[x].size(); i ++) {
            // Si ya choque con esa roca
            if( mark[ { rocasX[x][i], y } ] ) continue;
            // Si es uno del costado
            if( rocasX[x][i] - 1 == y || rocasX[x][i] + 1 == y) continue;

            mark[ { rocasX[x][i], y } ] = true;
            pasos = min(pasos, Solve(x, rocasX[x][i] < x ? rocasX[x][i] + 1 : rocasX[x][i] - 1, endx, endy) );
            mark[ { rocasX[x][i], y } ] = false;
        }
    }

    return pasos;

}


int main() {

   ios_base::sync_with_stdio(0);
   cin.tie(0);


    int H, W, N;
    cin >> H >> W >> N;
    int sx, sy;
    cin >> sx >> sy;
    int ex, ey;
    cin >> ex >> ey;

    for(int i = 0; i < N; i ++) {
        int x, y;
        cin >> x >> y;
        if( rocasX.find(x) != rocasX.end() ) rocasX[x] = vector<int>();
        if( rocasY.find(y) != rocasY.end() ) rocasY[y] = vector<int>();
        
        rocasX[x].push_back(y);
        rocasY[y].push_back(x);
    }

    // for(auto g : rocasX)
    //     for(auto i: g.second)
    //         cout << i << "\n";


    int sol = Solve(sx, sy, ex, ey);

    sol = ( sol == inf ) ? -1 : sol;

    cout << sol;
}
