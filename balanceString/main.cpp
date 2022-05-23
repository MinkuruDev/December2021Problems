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
int n, l, cnt[3];
string s;
void inputAndInit(){
    cin >> n;
    l = n / 3;
    cin >> s;
    cnt[0] = cnt[1] = cnt[2] = 0;
    fow(i,0,n){
        cnt[s[i] - '0']++;
    }
}

/// Process ///
void solve(int testIndex){
    int i = 0, j = 2;
    while(cnt[0] != l || cnt[1] != l || cnt[2] != l){
        while(cnt[i] != l) i++;
        while(cnt[j] != l) j--;

        if(cnt[i]<cnt[j]){
            fow(k,0,n){
                if(s[k] == '0' + i) s[k] = '0' + j;
            }
        }else{
            red(k,n-1,0){
                if(s[k] == '0' + j) s[k] = '0' + j;
            }
        }
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
