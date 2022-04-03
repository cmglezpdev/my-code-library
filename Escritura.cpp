#include<bits/stdc++.h>

using namespace std;

#define MAXN 1000100

struct tnode{
    int child[26];
    bool leaf;
}TRIE[MAXN];

string s;
int CANT = 0;
vector< string > v;

void Insert_Trie(){
    int sz = (int)s.size();
    int now = 0;

    for(int i = 0; i < sz; i ++){
        if( !TRIE[now].child[ s[i] - 'a' ] )
            TRIE[now].child[ s[i] - 'a' ] = ++CANT;
        now = TRIE[now].child[ s[i] - 'a' ];
    }
    TRIE[now].leaf = true;
}


int Find_Trie( int x ){
    int cont = 1, sz = (int)v[x].size();
    int now = TRIE[0].child[ v[x][0] - 'a' ];
    for(int i = 1; i < sz; i ++){
        int c = 0;
        for(int j = 0; j < 26; j ++){
            if( TRIE[now].child[ j ] ) c ++;
        }
        if( c != 1 || TRIE[now].leaf == true ) cont ++;
        now = TRIE[now].child[ v[x][i] - 'a' ];
    }
    return cont;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

        int N; cin >> N;

        for( int i = 0; i < N; i ++ ){
            cin >> s;
            v.push_back( s );
            Insert_Trie();
        }
        int Prom_total = 0;

        for(int i = 0; i < N; i ++)
            Prom_total += Find_Trie( i );

        cout.precision( 2 );
        cout << fixed << (double)Prom_total / N;

}