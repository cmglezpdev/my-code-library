#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 1;
int arr[maxn];
bool mark[maxn];


int binary_search(int found, int l, int r) {
    if(l > r)
        return -1;
    
    if(l == r)
        return( found == arr[l] && !mark[l] ) ? l : -1;

    int piv = (l + r) / 2;

    if( arr[piv] == found && !mark[piv] )
        return piv;

    int x = -1;

    if(found == arr[piv]) {
        x = binary_search(found, l, piv);
        if(x != -1) return x;
        x = binary_search(found, piv + 1, r);
        if(x != -1) return x;
    }

    if( found < arr[ piv ] ) 
        return binary_search(found, l, piv);
        
    return binary_search(found, piv + 1, r);
}



int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i ++) {
        cin >> arr[i];
        mark[i] = false;
    }

    sort(arr + 1, arr + n + 1);


    bool ok = true;
    while( ok && m -- ) {
        int x; cin >> x;

        int idx = binary_search(x, 1, n);
        if(idx != -1) mark[idx] = true;
        ok = (idx != -1);
    }

    if( ok )
        cout << "Yes\n";
    else cout << "No\n";

}
