#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fow(i,a,b) for(auto i = a; i<b; i++)
#define rep(i,a,b) for(auto i = a; i<=b; i++)
#define red(i,a,b) for(auto i = a; i>=b; i--)
#define repa(i,a) for(auto i: a)
#define db(x) cout << #x << " = " << x << endl
#define el cout << endl
#define getBit(n,i) ((n>>i)&1)
#define mod 1000000007ll
#define MAX 10000

typedef long long ll;
using namespace std;

/// Global variable and input ///
ll a,b,c;
void input(){
    cin >> a >> b >> c;
}

/// Process ///
void process(){
    ll sum = 0;
    ll s = sqrt(c);
    if(s>b){
        rep(i,a,b) sum += c%i;
        cout << sum%mod << endl;
        return;
    }
    if(s<a){
        /*ll ca = c/a;
        ll ci = c/(ca-1) - 1;
        ll r = ci;
        ll l = a;
        ll n = (c%l - c%r)/ca + 1;
        sum += n*(c%r) + ca*n*(n-1)/2;*/
        s = c/a;
    }else{
        rep(i,a,s){
            sum += c%i;
        }
        sum %= mod;
    }

    ll cb = c/b;
    ll ci = c/(cb+1) + 1;
    ll r = b;
    ll l = ci;
    ll n = (c%l - c%r)/cb + 1;
    sum += n*(c%r) + cb*n*(n-1)/2;

    fow(i,++cb,s){
        r = c/i;
        l = c/(i+1) + 1;
        n = (c%l - c%r)/i + 1;
        sum += (n*(c%r) + i*n*(n-1)/2)%mod;
    }

    fow(i,a,l){
        sum += c%i;
    }

    cout << sum%mod << endl;
}

void test(){
    ll sum = 0;
    rep(i,a,b){
        sum = (sum + c%i)%mod;
    }

    cout << sum%mod << endl;
}

int main(){
    fast_io;
    input();
    //test();
    int testCase = 1;
    if(testCase == 0) cin >> testCase;
    while(testCase--)
        process();
        //test();
    return 0;
}
