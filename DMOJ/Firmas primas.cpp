#include<bits/stdc++.h>

using namespace std;

const int maxn = 1000005;
vector<int> v;

map<int, int> m;

void Div(int n){
    for(int i = 2; i * i <= n; i ++){
        while( n%i == 0 ){
            n /= i;
            m[i] ++;
        }
    }
    if(n > 1) m[n] ++;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n; cin >> n;
    Div(n);

    int cnt = 1;
    for(auto i : m){
        cnt *= ( i.second + 1 );
        v.push_back(i.second);
    }

    sort(v.begin(), v.end());
    for( auto i : v )
        cout << i << ' ';
    cout << '\n' << cnt;
}