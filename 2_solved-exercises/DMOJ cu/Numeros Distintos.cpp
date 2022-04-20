#include<bits/stdc++.h>

using namespace std;

const int maxn = 100005;
const int maxnum = 1000006;

int cnt[maxnum], h[maxn], blockSize;
struct query{
    int l, r, idx;
}mo[maxn];
int solve = 0;
int sol[maxn];

bool cmp(query &a, query &b){
    if( a.l/blockSize != b.l/blockSize )
        return a.l < b.l;
    return a.r > b.r;
}

void change( int a, int k){
    if( cnt[a] == 0 && cnt[a] + k == 1 ) solve ++;
    if( cnt[a] == 1 && cnt[a] + k == 0 ) solve --;
    cnt[a] += k;
}


int main(){

    int n; cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> h[i];
    }
    blockSize = ceil(sqrt(n)) + 1;
    int q; cin >> q;
    for(int i = 1; i <= q; i ++){
        cin >> mo[i].l >> mo[i].r;
        mo[i].idx = i;
    }
    sort(mo + 1, mo + 1 + q, cmp);

    int l = 1, r = 0;
    for(int i = 1; i <= q; i ++){
        int lq = mo[i].l, rq = mo[i].r;
        while(r < rq) change(h[++r], 1);
        while(l < lq) change(h[l++], -1);
        while(r > rq) change(h[r--], -1);
        while(l > lq) change(h[--l], 1);
        sol[mo[i].idx] = solve;
    }
    for(int i = 1; i <= q; i ++)
        cout << sol[i] << '\n';
}