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
#define MAX 10000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int n;
ll total;
ll cnt[12];

void backtracking(string trace, char neww){
    trace += neww;
    if(trace.size() == n){
        total++;
        //db(trace);
        return;
    }

    rep(i,'a',(char)neww+1){
        backtracking(trace, i);
    }
}

/// Global variable and input, init ///
void inputAndInit(){
    fow(i,1,12){
        n = i;
        total = 0;
        backtracking("", 'a');
        cnt[i] = total;
        //db(i); db(total);
    }
}

/// Process ///
void solve(int testIndex){
    int asd; cin >> asd;
    cout << cnt[asd] << endl;
}

void test(){

}

int main(){
    fast_io;
    inputAndInit();
    //test();
    int testCase = 0;
    if(testCase == 0) cin >> testCase;
    fow(i,0,testCase)
        solve(i);
    return 0;
}
