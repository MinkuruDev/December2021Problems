#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define vti vector<int>
#define vtv vector<vti>
#define msi map<string, int>
#define fow(i,a,b) for(auto i = a; i<b; i++)
#define rep(i,a,b) for(auto i = a; i<=b; i++)
#define red(i,a,b) for(auto i = a; i>=b; i++)
#define repa(i,o) for(auto i: o)
#define db(x) cout << #x << " = " << x << endl;
#define getBit(n,i) ((n>>i)&1)
#define MAX 1000

typedef long long ll;
using namespace std;

struct Point{
    int x,y;

    int operator-(const Point other){
        return abs(x-other.x) + abs(y-other.y);
    }

    bool operator<(const Point other){
        if(x==other.x)
            return y < other.y;
        return x < other.x;
    }
};

/// Global variable and input ///
Point houses[MAX];
int n;
void input(){
    cin >> n;
    fow(i,0,n){
        cin >> houses[i].x >> houses[i].y;
    }
}

/// Process ///
void process(){
    Point selected = houses[0];
    double minDistance = INT_MAX;
    fow(i,0,n){
        double sum = 0;
        fow(j,0,n){
            if(i==j) continue;
            sum += houses[j] - houses[i];
        }
        double avg = sum/(n-1);
        if(minDistance == avg)
            selected = selected < houses[i] ? selected : houses[i];
        if(avg < minDistance){
            minDistance = avg;
            selected = houses[i];
        }

    }

    cout << selected.x << " " << selected.y;
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
