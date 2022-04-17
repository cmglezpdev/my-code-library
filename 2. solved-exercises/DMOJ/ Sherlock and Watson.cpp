#include<bits/stdc++.h>

using namespace std;


#define int long long

const int maxn = 1e5 + 1;
const int maxnum = 1e6 + 1;
const int sqr = 325;
int abi[maxnum];
int A[maxn],B[maxn];
int solution[maxn];
int n, q;

void updateAbi(int idx, int v){
    for( ; idx <= n; idx += (idx&(-idx)) ){
        abi[idx] += v;
    }
}

int query(int idx){
    int res = 0;
    for( ; idx; idx -= (idx &(-idx)) ){
        res += abi[idx];
    }
    return res;
}

int queryAbi(int l, int r){
    return query(r) - query(l - 1);
}

struct query{
    int l, r, idx;
    const bool operator < (const query &a){
        if( l/sqr != a.l/sqr ) return l < a.l;
        return r > a.r;
    }
}mo[maxn];

set<int>s;
map<int,int>p;
main(){

    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> B[i],s.insert(B[i]);

    int cnt = 0;

    for(auto i : s){
        cnt++;
        p[i] = cnt;
    }

    for(int i=1;i<=n;i++){
        A[i] = p[B[i]];
    }

    cin >> q;
    for(int i = 1; i <= q; i ++){
        int x, y;
        cin >> x >> y;
        mo[i].l = x, mo[i].r = y;
        mo[i].idx = i;
    }

    sort(mo + 1, mo + q + 1);

    int l = 1, r = 0;
    int answer = 0;
    for(int i = 1; i <= q; i ++){
        int lq = mo[i].l, rq = mo[i].r;

        while(l < lq){
            answer -= queryAbi(1, A[l] - 1);
            updateAbi(A[l++], -1);
        }
        while(l > lq){
            answer += queryAbi(1, A[--l] - 1);
            updateAbi(A[l], 1);
        }
        while(r < rq){
            answer += queryAbi(A[++r] + 1, n);
            updateAbi(A[r], 1);
        }
        while(r > rq){
            answer -= queryAbi(A[r] + 1, n);
            updateAbi(A[r--], -1);
        }
        solution[ mo[i].idx ] = answer;

    }

    for(int i = 1; i <= q; i ++)
        cout << solution[i] << '\n';

}