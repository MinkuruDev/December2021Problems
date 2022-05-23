#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define vti vector<int>
#define vtv vector<vti>
#define msi map<string, int>
#define fow(i,a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<=b; i++)
#define red(i,a,b) for(int i = a; i>=b; i++)
#define db(x) cout << #x << " = " << x << endl;
#define getBit(n,i) ((n>>i)&1)
#define MAX 10000
#define mod 1000000007

typedef long long ll;
using namespace std;

/// Global variable and input ///

void input(){

}

ll powMod(ll n, ll times){
    ll result = 1;
    ll sum = 0;
    while(times--){
        result *= n;
        result %= mod;
        sum += result;
    }

    return sum%mod;
}

/// Process
void process(){
    ll l,n;
    while(true){
        cin >> n >> l;
        if(n==0 || l==0){
            break;
        }

        cout << powMod(n,l) << endl;
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
