/// Contando prefijos palindromicos by CodeExtreme
#include<bits/stdc++.h>

using namespace std;

#define MAXN 100010
#define M 1e9+7
#define A 71
typedef long long ll;

ll HD[MAXN];
ll HR[MAXN];
ll Pow[MAXN];

ll kmod( ll a, ll b ){
    return( a%b + b )%b;
}

void build_pow( int n ){
    Pow[0] = 1ll;
    for(int i = 1; i <= n; i ++)
        Pow[i] = kmod( Pow[i - 1] * A, M );
}

void build_hash( string &c ){
    int sz = (int)c.size();
    HD[0] = HR[0] = 0;
    for(int i = 1, k = sz - 1; i < sz; i ++, k --){
        HD[i] = kmod( HD[i - 1] * A + c[i], M );
        HR[i] = kmod( HR[i - 1] * A + c[k], M );
    }
}

bool Is_not_lettle( char p ){
    return ( p != 'A' && p != 'E' && p != 'I' && p != 'O' && p != 'U' ) ? 1 : 0;
}

ll aux_hash( int star, int fin, bool AC ){
    if( AC )
        return kmod( HD[fin], M );
    else return kmod( HR[fin] - HR[star - 1] * Pow[fin - star + 1], M );
}

int Counting_Prefix_Palindromes( string &c ){
    int cant = 0;
    bool stop = 0;
    int sz = (int)c.size();
    sz --;
    for(int i = 1; i <= sz; i ++){
        if( Is_not_lettle( c[i] ) && !stop )
            continue;
        stop = 1;
        ll hashd = aux_hash( 1, i, 1 );
        ll hashr = aux_hash( sz - i + 1, sz, 0 );
        if( hashd == hashr )
            cant ++;
    }
    return cant;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n; cin >> n;

    while( n -- ){

        string c; cin >> c;
        c = ' ' + c;
        int sz = (int)c.size();
        build_hash( c );
        build_pow( sz + 10 );

        cout << Counting_Prefix_Palindromes( c ) << "\n";
    }


}