#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

const int maxn = 1e5 + 1;

int main(){

   string a, b;
   char o;
    cin >> a >> o >> b;
    if( a.size() < b.size() )
        swap(a, b);

    switch(o) {
        case '*':
            for(int i = 1; i < b.size(); i ++)  
                a.push_back('0'); 
            break;
        case '+':
            if( a.size() == b.size() ) {
                a[0] = '2';
                break;
            }
            a[ a.size() - b.size() ] = '1';
            break;
    }

    cout << a;

}