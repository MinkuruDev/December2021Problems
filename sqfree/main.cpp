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
#define MAX 10000

typedef long long ll;
using namespace std;

/// Global variable and input ///
map<ll,bool> isSquare;
void input(){

}

int isSquareFree(ll n){
    int i = 2;
    while(i*i<=n){
        if(n%(i*i) == 0) return 0;
        i++;
    }

    return 1;
}

ll countFreeSquare(ll n){
    ll s = sqrt(n);
    ll cur=2,curS=4,nxtS=9;
    isSquare[curS] = true;
    ll curP = 1;
    while(cur<=s){

    }
}

/// Process ///
void process(){
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
    }

}

void test(){
    cout << 0;
}

int main(){
    fast_io;
    input();
    test();
    //process();
    return 0;
}
