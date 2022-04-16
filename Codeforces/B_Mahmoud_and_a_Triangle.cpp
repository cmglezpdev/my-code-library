#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;
vector<int> v;
bool m[maxn];

bool isT(int x, int y, int z) {
    return (x + y > z && x + z > y && y + z > x);
}

bool search(int l, int r, int x, int y, int f) {
    while(l <= r) {
        if( l == r) {
            if( m[l] ) return false;
            return isT(x, y, v[l]);
        }
        int mid = (l + r) / 2;
        int z = v[mid];

        if( !m[mid] && isT(x, y, z) ) {
            return true;
        } 
        if( z >= f || x + z <= y || y + z <= x ) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return false;
}

int main(){

    int n; cin >> n;
    for(int i = 0; i < n; i ++) {
        int x; cin >> x;
        v.push_back( x );
        m[i] = false;
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i ++) {
        for(int j = i + 1; j < n; j ++) {
            int x = v[i];
            int y = v[j];
            m[i] = m[j] = true;
            // cout << x << ' ' << y << endl;
            bool existz = search(0, n - 1, x, y, x + y);
            if( existz ) {
                cout << "YES";
                return 0;
            }
            m[i] = m[j] = false;
        }
    }
    cout << "NO";
}