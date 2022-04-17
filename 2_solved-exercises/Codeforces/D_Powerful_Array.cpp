#include<bits/stdc++.h>
 
using namespace std;
 
const int maxn = 200005;
const int maxdigit = 1000005;
typedef long long ll;
int blockSize;
 
struct query{
    int l, r, id;
}mo[maxn];
 
bool cmp_mo(query &a, query &b){
    if( a.l/blockSize != b.l/blockSize )
        return a.l < b.l;
    return a.r > b.r;
}
int A[maxn], cnt[maxdigit];
ll answer = 0;
ll solve[maxn];
 
void change( int n, int k){
    answer -= (ll)cnt[n]*cnt[n] * n;
    cnt[n] += k;
    answer += (ll)cnt[n]*cnt[n] * n;
}
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n, q;
    cin >> n >> q;
    blockSize = ceil(sqrt(n)) + 1;
    for(int i = 1; i <= n; i ++) cin >> A[i];
 
    for(int i = 1; i <= q; i ++){
        cin >> mo[i].l >> mo[i].r;
        mo[i].id = i;
    }
 
    sort(mo + 1, mo + 1 + q, cmp_mo);
    int l = 1, r = 0;
    for(int i = 1; i <= q; i ++){
        int lq = mo[i].l, rq = mo[i].r;
        while(l < lq) change(A[l++], -1);
        while(r > rq) change(A[r--], -1);
        while(l > lq) change(A[--l], 1);
        while(r < rq) change(A[++r], 1);
        solve[mo[i].id] = answer;
    }
 
    for(int i = 1; i <= q; i ++)
        cout << solve[i] << '\n';
}