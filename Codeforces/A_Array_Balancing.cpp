// No creo que de en todos los casos, por lo que puede ser hackeado
#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 1e5 + 1;

int main(){

    int tt; cin >> tt;
    while(tt --) {
       int n; cin >> n;
       vector<ll> a(n), b(n);

       for(int i = 0; i < n; i ++)  cin >> a[i];
       for(int i = 0; i < n; i ++)  cin >> b[i];

        ll suma = 0, sumb = 0; 
        for(int i = 0; i < n; i ++) {
            if( a[i] < b[i] ) swap(a[i], b[i]);
            if(i > 0) {
                suma += abs(a[i] - a[i - 1]);
                sumb += abs(b[i] - b[i - 1]);
            } 
        }   
        cout << suma + sumb << '\n';
    }
}