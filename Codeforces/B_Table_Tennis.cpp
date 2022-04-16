#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 505;
int player[maxn];

int main(){

    ll n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> player[i];
    }

    if( player[1] == n || k >= n ) {
        cout << n;
        return 0;
    }

    int pl = 1;
    int cnt = 0;
    for(int i = 2; i <= n; i ++) {
        if( cnt == k ) break;
        if( player[pl] == n ) {
            break;
        }
        if( player[pl] > player[i] ) {
            cnt ++;
        } else {
            pl = i;
            cnt = 1;
        }
    }

    cout << player[pl];
}