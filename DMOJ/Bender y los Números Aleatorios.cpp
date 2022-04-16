#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int length(int n) {
    return floor(log10(n)) + 1;
}

int nth(int i, int n) {
    i = length(n) - i + 1;
    int x = pow(10, i - 1);
    int rest = n / x;
    return rest % 10;
}

int main(){

    int n; cin >> n;
    
    n *= n;
    int result = 0;

    if( length(n) == 7 ) {
        for(int i = 2; i <= 5; i ++)
            result = result * 10 + nth(i, n);
    } else {
        for(int i = 3; i <= 6; i ++)
            result = result * 10 + nth(i, n);
    }
    cout << result << '\n';
}