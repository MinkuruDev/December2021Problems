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
#define MAX 100000000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

bool isPrime(int n){
    int s = sqrt(n);
    rep(i,2,s){
        if(n%i==0) return false;
    }

    return true;
}

/// Global variable and input, init ///
int t[MAX]; bool prime[100];
int l[100], r[100], M, te;
void inputAndInit(){
    prime[0] = prime[1] = false;
    fow(i,2,100){
        prime[i] = isPrime(i);
    }

    M = 0;
    cin >> te;
    fow(i,0,te){
        cin >> l[i] >> r[i];
        if(r[i] > M) M = r[i];
    }

    t[0] = 0;
    ll temp;
    rep(i,1,M){
        temp = i;
        int sumDig = 0;
        while(temp){
            sumDig += temp%10;
            temp /=10;
        }
        t[i] = t[i-1] + prime[sumDig];
    }
}

/// Process ///
void solve(int testIndex){
    fow(i,0,te){
        cout << t[r[i]] - t[l[i]-1] << endl;
    }

}

void test(){

}

int main(){
    fast_io;
    inputAndInit();
    //test();
    int testCase = 1;
    if(testCase == 0) cin >> testCase;
    fow(i,0,testCase)
        solve(i);
    return 0;
}
