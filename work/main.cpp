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

/// Global variable and input, init ///
ll a[100], b[100],m;
int n;
void inputAndInit(){
    cin >> n >> m;
    fow(i,0,n){
        cin >> a[i] >> b[i];
        b[i]++;
    }
}

/// Process ///
void solve(int testIndex){
    ll days = 0, prod = 0;

    do{
        days++;
        fow(i,0,n){
            if(days % b[i]){
                prod += a[i];
            }
        }
    }while(prod < m);

    cout << days << endl;
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
