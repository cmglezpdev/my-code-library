#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;
int t[maxn];
pair<int, int> v[maxn];

int main(){

   int n; cin >> n;
   int time = 0;
   for(int i = 1; i <= n; i ++) {
        cin >> t[i];
        time += t[i];
   }    
    int m; cin >> m;
    for(int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        v[i] = make_pair(x, y);
    }

    int resp = -1;
    for(int i = 1; i <= m; i ++) {
        if( time >= v[i].first && time <= v[i].second ) {
            resp = time;
            break;
        } 
        if( time <= v[i].first ) {
            resp = v[i].first;
            break;
        }
    }

    cout << resp;
}