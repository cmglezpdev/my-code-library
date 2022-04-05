#include<bits/stdc++.h>

using namespace std;

#define ll long long

bool buildNumber(ll a, ll b, vector<ll> &v) {

    if(a > b)
        return false;
    if(a == b)
        return true;

   v.push_back(2ll * a);
   bool y = buildNumber(2ll * a, b, v);
   if( y ) return true;
   v.pop_back();

   v.push_back(10ll*a + 1ll);
   bool x = buildNumber(10ll * a + 1ll, b, v);
   if( x ) return true;
   v.pop_back();


    return false;
}


void Solve(ll a, ll b) {
    vector<ll> v;
    v.push_back(a);
    bool build = buildNumber(a, b, v);

    if( !build ) {
        cout << "NO\n";
        return;
    }
    
    if(v[v.size()-1] != b) 
    v.push_back(b);

    cout << "YES\n";
    cout << v.size() << '\n';

    
    for(int i = 0; i < v.size(); i ++) {
        cout << v[i];
        if(i != v.size() - 1) cout << ' ';
    }

}




int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b;
    cin >> a >> b;

    Solve(a, b);

}