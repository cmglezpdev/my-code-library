#include<bits/stdc++.h>

using namespace std;

// Implementation using fast factorization O(sqrt(n))
int phi_v1(int n) {
    int phi = n;
    for(int i = 2; i*i <= n; i ++) {
        if( n%i == 0 ) {
            while(n%i == 0) n /= i;
            phi -= phi / i;
        }
    }
    // if is prime
    if( n > 1 ) phi -= phi / n;
    return phi;
}


// Implementation using same idea as Sieve of Eratosthenes O(nlog^2n)
vector<int> phi_v2(int n) {
    vector<int> phi(n + 1);
    for(int i = 0; i <= n; i ++) phi[i] = i;

    for(int i = 2; i <= n; i ++ ) {
        if( phi[i] !=i ) continue;
        for(int j = i; j <= n; j += i)
            phi[j] -= phi[j] / i;
    }

    return phi;
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

}

// https://cp-algorithms.com/algebra/phi-function.html