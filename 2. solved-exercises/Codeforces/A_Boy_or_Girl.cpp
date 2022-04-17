#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int main(){

   string name; cin >> name;
   set<char> s;
   for(auto c: name)
    s.insert(c);

    if( s.size()%2 == 0 )
        cout << "CHAT WITH HER!";
    else cout << "IGNORE HIM!";
}