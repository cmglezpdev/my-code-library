#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const int maxn = 2e4 + 1;
const int maxm = 1e1 + 1;

map< pair<int, int>, int > message;
int ans[maxn];
int cntmschat[maxm];
vector<int> chat[maxn]; 

int main(){

    FAST

    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            bool x; cin >> x;
            if( x ) 
                chat[i].emplace_back(j);
        }
    }

    for(int i = 1; i <= k; i ++) {
        int x, y;
        cin >> x >> y;
        message[ make_pair(x, y) ] ++;
    }

    for( auto &ms : message ) {
        int user = ms.first.first;
        int mschat = ms.first.second;
        int cntms = ms.second;

        cntmschat[ mschat ] += cntms;
        ans[ user ] -= cntms;
    }

    for(int i = 1; i <= n; i ++) {
        for( auto &c: chat[i] )
            ans[i] += cntmschat[c];
        cout << ans[i] << ' ';
    }
}