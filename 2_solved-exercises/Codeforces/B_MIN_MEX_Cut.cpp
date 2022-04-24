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
        string s; cin >> s;
        int n = s.size();
        int mex = 0;
        for(int i = 0; i < n; i ++) {
            if( s[i] == '1' ) continue; 
            while( i < n && s[i] == '0' ) i ++;
            i --;
            mex ++;
        }
        mex = min( 2, mex );
        cout << mex << '\n';
    } 
}