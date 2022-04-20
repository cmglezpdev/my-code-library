#include<bits/stdc++.h>

using namespace std;

struct node{
    int abc[30];
    int cont;
    node(){
        fill(abc, abc + 30, -1);
        cont = 0;
    }
};

vector<node> trie;
int ascii(char x){
    return x - 'a';
}

void addw(string &w){
    int nodo = 0;
    for(auto &u : w){
        if(trie[nodo].abc[ascii(u)] == -1){
            trie[nodo].abc[ascii(u)] = trie.size();
            trie.push_back(node());
        }
        nodo = trie[nodo].abc[ascii(u)];
        trie[nodo].cont ++;
    }
}

int findw(string &w){
    int nodo = 0;
    for(auto &u : w){
        if(trie[nodo].abc[ascii(u)] == -1) return 0;
        nodo = trie[nodo].abc[ascii(u)];
    }
    return trie[nodo].cont;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
 trie.push_back(node());
    for(int i = 1; i <= n; i ++){
        string op, w;
        cin >> op >> w;
        if(op == "add"){
            addw(w);
        }
        if(op == "find"){
            cout << findw(w) << '\n';
        }
    }

}