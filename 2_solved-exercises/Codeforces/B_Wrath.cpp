#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e6 + 1;

int l[maxn];

int main(){

    int n; cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> l[i];
   
    int ans = 0, kill = n + 1;
    for(int i = n; i >= 1; i --) {
        if( i < kill ) ans ++;
        kill = min( kill, i - l[i] );
    }

    cout << ans;
}