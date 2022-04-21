#include<bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
#define int long long
struct matrix{
    int value[2][2];
    matrix(int x){
        for(int i = 0; i < 2; i ++){
            for(int j = 0; j < 2; j ++)
                value[i][j] = 0;
            value[i][i] = x;
        }
    }
    int *operator [](int row){
        return value[row];
    }
    const int *operator [] (int row) const{
        return value[row];
    }
};

const matrix operator *(const matrix a, const matrix b){
    matrix sol(0);
    for(int i = 0; i < 2; i ++)
        for(int j = 0; j < 2; j ++)
            for(int k = 0; k < 2; k ++){
                sol[i][j] += (long long)(a[i][k]*b[k][j])%mod;
                if(sol[i][j] >= mod) sol[i][j] -= mod;
            }
    return sol;
}

matrix kpow(matrix x, int n){
    matrix sol(1);
    while(n){
        if(n&1) sol = sol * x;
        x = x * x;  
        n /= 2;
    }
    return sol;
}

int fibonacci(int n, const vector<int> &v, const matrix &M){
    auto P = kpow(M, n - 1);
     int sol = 0;
    for(int i = 0; i < 2; i ++){
        sol += (long long)(v[i]*P[i][0])%mod;
        if(sol >= mod) sol -= mod;
    }
    return sol;
}


 main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    matrix M(0);
    M[0][0] = 1; M[0][1] = 1;
    M[1][0] = 1; M[1][1] = 0;

    vector<int> v{1, 0};

    int ts; cin >> ts;
    while(ts --){
        int l, r;
        cin >> l >> r;
        long long res = (long long)(fibonacci(r + 2, v, M) - fibonacci(l + 1, v, M))%mod; 
        if(res < 0) res += mod;
        cout << res << '\n';
    }


}