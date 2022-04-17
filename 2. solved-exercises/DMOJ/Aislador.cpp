#include<bits/stdc++.h>

using namespace std;

const int maxn = 100005;
typedef long long ll;
int a[maxn];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    ll sum = 0;

    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        sum += (ll)a[i];
    }

    sort(a + 1, a + n + 1);

    int i, k;
    ll aux_sum = 0;
    for(i = 1, k = n; i < k; i ++, k --){
        aux_sum += (ll)max(0, a[k] - a[i]);
    }
    cout << (long long)(sum + aux_sum);

}