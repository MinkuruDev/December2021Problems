/***************************************************\
*                                                   *
*   000   000       111        00000       11111    *
*   0000 0000      11 11       00  00     11        *
*   00 000 00     11   11      00000       11111    *
*   00     00    111111111     00  00          11   *
*   00     00   11       11    00   00     11111    *
*                                                   *
\***************************************************/

#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fow(i,a,b) for(auto i = a; i<b; i++)
#define rep(i,a,b) for(auto i = a; i<=b; i++)
#define red(i,a,b) for(auto i = a; i>=b; i--)
#define repa(i,a) for(auto i: a)
#define db(x) cout << #x << " = " << x << endl
#define el cout << endl
#define getBit(n,i) ((n>>i)&1)
#define mod 1000000007
#define MAX 10000

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

struct Point{
    ld x,y;

    Point() = default;

    Point(ld a, ld b){
        x = a;
        y = b;
    }
};

/// Global variable and input, init ///

void inputAndInit(){

}

ld triangleSquare(Point a, Point b, Point c){
    return abs((a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y))/2.0);
}

bool pointInsideTriangle(Point p, Point a, Point b, Point c){
    ld  area = triangleSquare(a,b,c),
        a1 = triangleSquare(p,a,b),
        a2 = triangleSquare(p,a,c),
        a3 = triangleSquare(p,b,c);

    return area == a1 + a2 + a3;
}

/// Process ///
void solve(int testIndex){
    Point a,b,c,d;
    cin >> a.x >> a.y >> b.x >> b.y
    >> c.x >> c.y >> d.x >> d.y;

    bool ai = pointInsideTriangle(a,b,c,d), // ai = a inside
         bi = pointInsideTriangle(b,a,c,d),
         ci = pointInsideTriangle(c,a,b,d),
         di = pointInsideTriangle(d,a,b,c);

    cout << ((ai || bi || ci || di)? "NO":"YES" )<< endl;
}

void test(){

}

int main(){
    fast_io;
    inputAndInit();
    //test();
    int testCase = 0;
    if(testCase == 0) cin >> testCase;
    fow(i,0,testCase)
        solve(i);
    return 0;
}
