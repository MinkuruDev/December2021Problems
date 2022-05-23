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
#define MAX 1000

typedef long long ll;
using namespace std;

/// Global variable and input ///
int a[MAX],n;
void input(){
    cin >> n;
    fow(i,0,n){
        cin >> a[i];
    }
}

/// Process ///
void process(){
    int maxNeg = -INT_MAX;
    int negCount = 0, zeroCount = 0;

    fow(i,0,n){
        if(a[i] == 0){
            zeroCount++;
        }else if(a[i] < 0){
            negCount++;
            if(a[i] > maxNeg) maxNeg = a[i];
        }
    }
        if(zeroCount >= 2){
            cout << 0 << endl;
            return;
        }

        int rmv = 0;

        if(negCount%2 == 1){
            rmv = maxNeg;
        }

        int rmvIndex = -1;
        fow(i,0,n){
            if(a[i] == rmv){
                rmvIndex = i;
                break;
            }
        }

        ll product = 1;
        fow(i,0,n){
            if(i == rmvIndex) continue;
            product *= 1ll * a[i];
            product %= mod;
        }

        cout << product << endl;

}

void test(){
    cout << (-100000000000)%mod << endl;
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
