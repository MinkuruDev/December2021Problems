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
#define MAX 500005

typedef long long ll;
using namespace std;

/// Global variable and input ///
string s;
int k,sz;
int a[MAX];
void input(){
    cin >> s; s = " " + s;
    sz = s.size();
    rep(i,0,sz){
        a[i] = 0;
    }
    cin >> k;
    int n,x,y;
    fow(i,0,k){
        cin >> n >> x >> y;
        a[x] += n;
        a[y+1] -= n;
    }

    rep(i,1,sz){
        a[i] += a[i-1];
    }
}

/// Process ///
void process(){
    fow(i,1,sz){
        s[i] += a[i]%26;
        if(s[i] > 'Z') s[i] -= 26;
        cout << s[i];
    }
    el;
}

void test(){

}

int main(){
    fast_io;
    input();
    //test();
    int testCase = 1;
    if(testCase == 0) cin >> testCase;
    while(testCase--)
        process();
    return 0;
}
