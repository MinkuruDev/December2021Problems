#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fow(i,a,b) for(auto i = a; i<b; i++)
#define rep(i,a,b) for(auto i = a; i<=b; i++)
#define red(i,a,b) for(auto i = a; i>=b; i++)
#define repa(i,a) for(auto i: a)
#define db(x) cout << #x << " = " << x << endl
#define el cout << endl
#define getBit(n,i) ((n>>i)&1)
#define MAX 200000

typedef long long ll;
using namespace std;

struct Point{
    int x,y;

    bool operator<(const Point other){
        if(x==other.x) return y<other.y;
        return x<other.x;
    }

    bool operator==(const Point other){
        return x==other.x && y==other.y;
    }
};

/// Global variable and input ///
Point p[MAX];
map<int, int> mix,miy;
ll sum = 0;
int n;
void input(){
    cin >> n;
    fow(i,0,n){
        cin >> p[i].x >> p[i].y;

        mix[p[i].x]++;
        miy[p[i].y]++;
    }

    sort(p,p+n);
}

/// Process ///
void process(){
    int testCase = 1;
    if(testCase <= 0) cin >> testCase;

    while(testCase--){
        if(mix[p[0].x] > 1){
            sum += --mix[p[0].x];
        }
        if(miy[p[0].y] > 1){
            sum += --miy[p[0].y];
        }
        int dupCount = 1;
        fow(i,1,n){
            if(mix[p[i].x] > 1){
                sum += --mix[p[i].x];
            }

            if(miy[p[i].y] > 1){
                sum += --miy[p[i].y];
            }
            if(p[i] == p[i-1]){
                sum -= dupCount++;
            }else{
                dupCount = 1;
            }
        }
        cout << sum << endl;
    }
}

void test(){

}

int main(){
    fast_io;
    input();
    //test();
    process();
    return 0;
}
