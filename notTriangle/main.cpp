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
using namespace std;

/// Global variable and input ///

void input(){

}

/// Process ///
void process(){
    ll n, k;
    cin >> n >> k;
    bool flag = true;
    if(n>=4){
        flag = false;
    }else{
        if(k<2) flag = false;
    }

    cout << (flag? "yes":"no") << endl;
}

void test(){

}

int main(){
    fast_io;
    input();
    //test();
    int testCase = 0;
    if(testCase == 0) cin >> testCase;
    while(testCase--)
        process();
    return 0;
}
