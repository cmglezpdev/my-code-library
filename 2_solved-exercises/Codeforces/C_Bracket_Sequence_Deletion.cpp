#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define ll long long

const ll B = 51LL;
const ll M = 1000000007LL;
const int maxn = 1e5 + 1;

int main(){

    FAST

    ll Pow[5 * maxn];
    Pow[0] = 1LL;
    for(int i = 1; i < 5 * maxn; i ++)
        Pow[i] = (Pow[i - 1] * B) % M;

    int tt; cin >> tt;
    while(tt --) {
        int n; cin >> n;
        string c; cin >> c;

        c = ' ' + c;
        ll hd[n + 1]; hd[0] = 0;
        ll hr[n + 1]; hr[0] = 0;
        for(int i = 1, j = n; i <= n; i ++, j --) {
            hd[i] = ((hd[i - 1] * B) % M + c[i])%M;
            hr[i] = ((hr[i - 1] * B) % M + c[j])%M;
        }


        int ansa = 0, ansb = n;
        for(int i = 1; i <= n; i ++) {
            if( c[i] == '(' && i + 1 <= n ) {
                ansa ++;
                i ++;
                ansb = n - i;
                continue;
            }
            if( c[i] == ')' ) {
                bool found = false;
                for(int j = i + 1; j <= n; j ++) {

                    ll hasha = (hd[j] - (hd[i - 1]*Pow[j - i + 1])%M) % M;
                    if( hasha < 0 ) hasha += M;
                    int r = n - (i - 1), l = n - j + 1;
                    ll hashb = (hr[r] - (hr[l - 1]*Pow[r - l + 1])%M) % M;
                    if( hashb < 0 ) hashb += M;
                
                    if( hasha == hashb ) {
                        ansa ++;
                        ansb = n - j;
                        i = j;
                        found = true;
                        break;
                    }
                }
                if(!found) break;
            }
        }

        cout << ansa << ' ' << ansb << '\n';
    }
   
}