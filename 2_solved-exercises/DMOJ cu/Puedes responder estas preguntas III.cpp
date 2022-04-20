#include<bits/stdc++.h>

using namespace std;

const int maxn = 50010;
int x[maxn];

int query(int l, int r){
    int sum = x[l], sol = x[l];
    l ++;
    for(int i = l; i <= r; i ++){
        sum = max(sum + x[i], x[i]);
        sol = max(sol, sum);
    }
    return sol;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> x[i];
    int s; cin >> s;
    while( s-- ){
        int a, b, c;
        cin >> a >> b >> c;
        if( a == 1 ){
            if(b > c) swap(a, b);
            cout << query(b, c) << '\n';
        }else{
            x[b] = c;
        }
    }

}