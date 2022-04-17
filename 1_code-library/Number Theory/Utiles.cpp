#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

LL Add(LL a, LL b, LL mod) {
    a += b;
    if( a >= mod )
        a -= mod;
    return a;
}

LL Subs(LL a, LL b, LL mod) {
    a -= b;
    if( a < 0)
        a += mod;
    return a;
}


LL Mult(LL a, LL b, LL mod) {
    LL q = (long double)a * b / mod;
    LL r = a * b - q * mod;
    r %= mod;
    if(r < 0) r += mod;
    return r;
}

LL PowMod( LL b, LL e, LL mod ) {
    if( e == 0 || b == 1LL ) return 1LL;
    if( e == 1LL ) return b;
    
    LL tmp = PowMod(b, e / 2LL, mod);
    tmp = Mult(tmp, tmp, mod);
    return Mult(tmp, PowMod(b, e%2LL, mod), mod);
}


int main() {

}