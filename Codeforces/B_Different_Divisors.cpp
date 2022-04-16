#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);


const int maxn = 4e4 + 1;
bool isp[maxn];
long long lcm(long long a, long long b) {
    return a * b / __gcd(a, b);
}

int main(){

    FAST
    vector<int> p;
    p.push_back(2);
    fill(isp, isp + maxn, true);
    for(int i = 3; i < maxn; i += 2) {
        if( !isp[i] ) continue;
        p.push_back(i);
        for(long long j = i * i; j < maxn; j += i) 
            isp[(int)j] = false;
    } 

    int tt; cin >> tt;
    while(tt --) {
        int d; cin >> d;
        long long a = 1;

        int idx = lower_bound(p.begin(), p.end(), a + d) - p.begin();
        long long b = p[idx];
    
        idx = lower_bound(p.begin(), p.end(), b + d) - p.begin();
        long long c = p[idx];

        long long ans = lcm(b, c);
        cout << ans << '\n';
    }
   
}