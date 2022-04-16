#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int main(){

   string expresion; cin >> expresion;
    int n = expresion.size();

    string a = "", b = "";
    char o;
   for(int i = 0; i < n; i ++) {
       if( expresion[i] != '+' && expresion[i] != '-' && expresion[i] != '/' && expresion[i] != '*' ) continue;
        o = expresion[i];
        a = expresion.substr(0, i);
        b = expresion.substr(i + 1);
        break;
   }

    int na = 0;
    for(int i = 0; i < a.size(); i ++) {
        na = na * 10 + (int)(a[i] - '0');
    }
    int nb = 0;
    for(int i = 0; i < b.size(); i ++) {
        nb = nb * 10 + (int)(b[i] - '0');
    }

    int ans = 0;

    if( o == '+' ) cout << na + nb;
    else if(o == '-') cout << na - nb;
    else if(o == '*') cout << na * nb;
    else cout << na / nb;

}