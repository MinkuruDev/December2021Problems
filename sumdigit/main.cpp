#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define vti vector<int>
#define vtv vector<vti>
#define msi map<string, int>
#define fow(i,a,b) for(auto i = a; i<b; i++)
#define rep(i,a,b) for(auto i = a; i<=b; i++)
#define red(i,a,b) for(auto i = a; i>=b; i++)
#define db(x) cout << #x << " = " << x << endl;
#define getBit(n,i) ((n>>i)&1)
#define MAX 10000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/// Global variable and input ///
ull pow10[16];
void input(){

}

void initPow10(){
    pow10[0] = 1;
    fow(i,1,16){
        pow10[i] = 10 * pow10[i-1];
    }
}

ull sumOfDigitsFrom1ToNUtil(ull n, ull a[])
{
    if (n < 10)
        return (n * (n + 1) / 2);

    ull d = (ull)(log10(n));
    ull p = (ull)pow10[d];
    ull msd = n / p;

    return (msd * a[d] + (msd * (msd - 1) / 2) * p +
            msd * (1 + n % p) +
            sumOfDigitsFrom1ToNUtil(n % p, a));
}

// Function to computer sum of digits in
// numbers from 1 to n
ull sumOfDigitsFrom1ToN(ull n)
{
    if(n<=0) return 0;
    ull d = (ull)(log10(n));
    ull a[d + 1];
    a[0] = 0; a[1] = 45;

    for(ull i = 2; i <= d; i++)
        a[i] = a[i - 1] * 10 + 45 *
               (ull)(pow10[i-1]);

    return sumOfDigitsFrom1ToNUtil(n, a);
}

/// Process ///
void process(){
    int T;
    cin >> T;
    while(T--){
        ull l,r;
        cin >> l >> r;
        if(l==0) l=1;

        cout << sumOfDigitsFrom1ToN(r) - sumOfDigitsFrom1ToN(l-1) << endl;
    }
}

void test(){

}

int main(){
    fast_io;
    input();
    initPow10();
    //test();
    process();
    return 0;
}
