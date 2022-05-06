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
        vector<int> sec(n + 1);
        for(int i = 1; i <= n; i ++) {
            cin >> sec[i];
        }


        int operations = 0;
        bool ok = true;
        for(int i = 2; i <= n; i ++) {
            if( sec[i] > sec[i - 1] ) continue;
            for(int j = i - 1; j >= 1; j --) {
                if( sec[j] < sec[j + 1] ) continue;
               
                while( sec[j] >= sec[j + 1] ) {
                    sec[j] /= 2;
                    operations ++;

                    if( sec[j] == 0 ) break;
                }
                if( sec[j] >= sec[j + 1] ) {
                    ok = false;
                    break;
                }
            }
        }

        if(ok)
            cout << operations << '\n';
        else cout << "-1\n";

    }
}