#include<bits/stdc++.h>

using namespace std;

int cnt[101];

int main() {

    int a, b, c;
    cin >> a >> b >> c;

    cnt[a] ++;
    cnt[b] ++;
    cnt[c] ++;

    cout << max(cnt[a], max(cnt[b], cnt[c])) << '\n';

}