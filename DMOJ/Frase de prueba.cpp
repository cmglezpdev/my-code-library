// ! INCOMPLETO

#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;
typedef long long ll;
ll B = 31LL;
ll MOD = 1e9 + 7 * 1LL;
ll Pow[maxn];
ll ha[maxn];
ll hb[maxn];
ll hc[maxn];

void buildPow(){
    Pow[0] = 1ll;
    for(int i = 1; i < maxn; i ++)
        Pow[i] = (Pow[i -1]*B)%MOD;
}

ll getHash(int l, int r, char x){

    if(x == 'a') {
         ll aux = (ha[l - 1]*Pow[r - l + 1])%MOD;
         return ((ha[r] - aux)%MOD + MOD)%MOD;
    }
    if(x == 'b') {
         ll aux = (hb[l - 1]*Pow[r - l + 1])%MOD;
         return ((hb[r] - aux)%MOD + MOD)%MOD;
    }
    if(x == 'c') {
         ll aux = (hc[l - 1]*Pow[r - l + 1])%MOD;
         return ((hc[r] - aux)%MOD + MOD)%MOD;
    }
    
}

bool search( ll hs, int ns, char in, int nin ) {

    if( in == 'a' ) {
        for(int i = 1; i + ns - 1 <= nin; i ++) {
            ll hin = getHash( i, i + ns - 1, in);
            if( hin == hs ) return true;
        }
    }

    return false;
}



int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b, c;
    cin >> a >> b >> c;
    a = ' ' + a;
    b = ' ' + b;
    c = ' ' + c;

    int na = a.size() - 1;
    int nb = b.size() - 1;
    int nc = c.size() - 1;

    for(int i = 1; i <= max(na, max(nb, nc)); i ++) {
        if( i <= na ) ha[i] = ( (ha[i - 1]*B)%MOD + a[i] )%MOD;
        if( i <= nb ) hb[i] = ( (hb[i - 1]*B)%MOD + b[i] )%MOD;
        if( i <= nc ) hc[i] = ( (hc[i - 1]*B)%MOD + c[i] )%MOD;
    }

    pair<int, char> aux[3];
    aux[0] = make_pair(na, 'a');
    aux[1] = make_pair(nb, 'b');
    aux[2] = make_pair(nc, 'c');

    sort( aux, aux + 2);
    int sol = na + nb + nc;

    // Buscar las cadenas de esas 3 que estan contenidas en otra

    // Buscar las esquinas que machean con otras esquinas 

}
