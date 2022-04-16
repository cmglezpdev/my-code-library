#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll B = 33;
const int maxn = 1000006;
ll H[maxn], Pow[maxn];
string s;


void buildPow(){
    Pow[0] = 1ll;
    for(int i = 1; i < maxn; i ++)
        Pow[i] = (Pow[i -1]*B)%MOD;
}

void buildHash(){
    fill(H, H + maxn, 0);
    int n = (int)s.size() - 1;
    for(int i = 1; i <= n; i ++){
        H[i] = (H[i - 1]*B)%MOD;
        H[i] += s[i];
        if(H[i] >= MOD) H[i] -= MOD;
    }
}

ll getHash(int l, int r){
    ll x = (H[l - 1]*Pow[r - l + 1])%MOD;
    return ((H[r] - x)%MOD + MOD)%MOD;
}

int solve(int l, int r){
    int ans = 0;
    while(l + 1 <= r){
        bool ok = false;
        for(int i = r; l+(r-i) < i && !ok; i --){
            ll hashl = getHash(l, l+(r-i));
            ll hashr = getHash(i, r);
            if(hashl == hashr){
                ok = true;
                ans += 2;
                l = l+(r-i+1), r = i-1;
                if(l == r) ans ++;
                break;
            }
        }
        if(!ok) return ans + 1;
    }
    return ans;
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    buildPow();
    int test; cin >> test;
    while(test --){
        cin >> s;
        int n = (int)s.size();
        s = ' ' + s;
        buildHash();
        cout << solve(1, n) << '\n';
    }



}