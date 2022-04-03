#include<bits/stdc++.h>

using namespace std;

typedef long long db;

struct point{
    db x, y;
    point (db x, db y){
        this->x = x, this->y = y;
    }
    const point operator + (point a){
        return {x + a.x, y + a.y};
    }
    const point operator - (point a){
        return{x - a.x, y - a.y};
    }
};
db cross(const point a, const point b){
    return (a.x * b.y - a.y * b.x);
}

int ccw(point a, point b, point c){
    b = b - a, c = c - a;
    if(cross(b, c) > 0) return +1;
    if(cross(b, c) < 0) return -1;
    return 0;
}

typedef vector<point> polygon;


bool isConvex(polygon g){
    int n = (int)g.size();
    if(n < 3) return 0;
    int pos = 0, neg = 0;
    for(int i = 0; i < n; i ++){
        if(ccw(g[i], g[(i+1)%n], g[(i+2)%n]) > 0) pos ++;
        if(ccw(g[i], g[(i+1)%n], g[(i+2)%n]) < 0)  neg ++;
    }
    return (!neg || !pos);
}



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int ts; cin >> ts;
    while(ts --){
        int n; cin >> n;
        polygon g;
        for(int i = 1; i <= n; i ++){
            db x, y;
            cin >> x >> y;
            g.push_back(point{x, y});
        }
        (isConvex(g))? cout << "Si\n" : cout << "No\n";
    }

 }