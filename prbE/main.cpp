#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fow(i,a,b) for(auto i = a; i<b; i++)
#define rep(i,a,b) for(auto i = a; i<=b; i++)
#define red(i,a,b) for(auto i = a; i>=b; i++)
#define repa(i,a) for(auto i: a)
#define db(x) cout << #x << " = " << x << endl
#define el cout << endl
#define getBit(n,i) ((n>>i)&1)
#define MAX 10000

typedef long long ll;
using namespace std;

/// Global variable and input ///
double h,a;
double half,full;
void input(){
    cin >> a >> h;
    half = h/6;
    full = h/3;
}

double calc(double i){
    return (h-i) * (a+(100-a)*((i-half)/(full-half)));
}

/// Process ///
void process(){
    int testCase = 1;
    if(testCase <= 0) cin >> testCase;
    while(testCase--){

        double M = max(h - h/3, (h-h/6) * a);
        double low = half, high = full;
        rep(j,1,100000){
            double i = (low + high) / 2;
            double r = calc(i);
            if(r>M){
                M = r;
            }
            if(calc((low+i)/2) > calc((i+high)/2)){
                high = i;
            }else{
                low = i;
            }
        }
        cout << fixed << setprecision(8) << M;
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
