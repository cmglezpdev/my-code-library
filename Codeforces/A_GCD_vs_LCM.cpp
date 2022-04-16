#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int main(){

    int n; cin >> n;
    for(int i = 1; i <= n; i ++ ){
       int x; cin >> x; 

        cout << x - 3 << " 1 1 1\n";
    }

}

/*
SOL KAREL


#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()
typedef long long ll;
typedef long double ld;
 
using namespace std;
 
int const MAXn = 1e6 + 2;
 
vector < int > primos;
bool criba[MAXn];
 
int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    primos.push_back(1);
    for(ll i = 2; i <= MAXn - 2; i++) {
        if(!criba[i]) primos.push_back(i);
        else continue;
        for(ll j = i * i; j <= MAXn - 2; j += i)
            criba[j] = true;
    }
 
    int t;
    cin>>t;
    for(int c = 1; c <= t; c++) {
        int n;
        cin>>n;
        int pos = lower_bound(all(primos), n - 2) - primos.begin();
        pos--;
        cout<<(n - 2) - primos[pos]<<" "<<primos[pos]<<" 1 1\n";
    }
 
    return 0;
}



*/