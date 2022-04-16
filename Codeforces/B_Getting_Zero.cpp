#include<bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 32768LL;
int Pow[16];
int mark[MOD + 1];

int main() {

    int n; cin >> n;
    vector<int> ans;
    for(int i = 0; i < n; i ++) {
        int x; cin >> x;

        queue<int> q;
        q.push(x);

        while(!q.empty()) {
            int num = q.front();
            q.pop();

            if( num == 0 ) break;

            if( !mark[ (2 * num)%MOD ] ) {
                mark[(2 * num)%MOD] = mark[num] + 1;
                q.push( (2 * num)%MOD );
            }
            if( !mark[(num + 1)%MOD] ) {
                mark[ (num + 1)%MOD ] = mark[num] + 1;
                q.push( (num + 1)%MOD );
            }
        }

        ans.push_back(mark[0]);
        fill(mark, mark + MOD + 1, 0);

    }

    for(auto a: ans) cout << a << ' ';

   


}

