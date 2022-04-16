#include<bits/stdc++.h>

using namespace std;

int Solve(int n, int m) {
    if(n == 1 && m == 1)
        return 0;
    
    if(n == 1) return m/2;
    if(m == 1) return n/2;

    if(n > m) swap(n, m);

    return n/2 * m +( ( n%2 == 0 ) ? 0 : m/2);
}

int main() {

    int n, m;
    cin >> n >> m;

    cout << Solve(n, m);


}