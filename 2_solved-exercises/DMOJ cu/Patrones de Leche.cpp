#include<bits/stdc++.h>

using namespace std;

const int maxn = 20005;
const int maxlg = 20;

struct SA{
    int nr[2];
    int p;
}L[maxn];

int P[maxlg][maxn];
int A[maxn];
int cnt, stp, n, k;

bool cmp_sa(struct SA a, struct SA b){
    return (a.nr[0] == b.nr[0]) ? a.nr[1] < b.nr[1] : a.nr[0] < b.nr[0];
}

void Suffix_Array(){

    for(int i = 0; i < n; i ++)
        P[0][i] = A[i];

    for( stp = 1, cnt = 1; cnt >> 1 < n; cnt <<= 1, stp ++ ){
        for(int i = 0; i < n; i ++){
            L[i].nr[0] = P[stp - 1][i];
            L[i].nr[1] = (i + cnt < n) ? P[stp - 1][i + cnt] : -1;
            L[i].p = i;
        }
        sort( L, L + n, cmp_sa );

        for(int i = 1; i < n; i ++)
        P[stp][ L[i].p ] = (i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1]) ? P[stp][L[i - 1].p] : i;

    }
}

int lcp( int x, int y ){
    if(x == y) return n - x;
    int k, sol = 0;
    for( k = stp - 1; k >= 0 && x < n && y < n; k --)
    if( P[k][x] == P[k][y] )
        sol += 1<<k, x += 1<<k, y += 1<<k;
    return sol;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

     cin >> n >> k;

     for(int i = 0; i < n; i ++){
        cin >> A[i];
     }

     Suffix_Array();

     int pos[maxn];
     for(int i = 0; i < n; i ++){
        pos[ P[stp - 1][i] ] = i;
     }
    int sol = 0;
    for(int i = 0; i + k - 1 < n; i ++){
        int LCP = lcp( pos[i], pos[i + k - 1] );
        sol = max( sol, LCP );
    }



    cout << sol;
}