#include<bits/stdc++.h>

using namespace std;

int mat[500][500];
int N, M, L;

void Floyd_Warshall(){
    for(int i = 1; i <= N; i ++)
        mat[i][i] = 0;

   for(int k = 1; k <= N; k ++)
       for(int i = 1; i <= N; i ++)
            for(int j = 1; j <= N; j ++)
                mat[i][j] = min( mat[i][j], max( mat[i][k], mat[k][j] ) );
}


int main(){


    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    cin >> N >> M >> L;

    for(int i = 1; i <= N ;i ++)
        for(int j = 1; j <= N; j ++)
            mat[i][j] = 1e9;

    for(int i = 0; i < M; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        mat[a][b] = c;
    }

    Floyd_Warshall();

    for(int i = 1; i <= L; i ++){
            int x, y;
            cin >> x >> y;
            if( mat[x][y] == 1e9 ) cout << "-1\n";
            else cout << mat[x][y] << "\n";
    }
}