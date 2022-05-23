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
int money[4];
int arrive[3], leave[3];
void inputAndInit(){
    cin >> money[1] >> money[2] >> money[3];
    fow(i,0,3){
        cin >> arrive[i] >> leave[i];
    }

    money[0] = 0;

    sort(arrive, arrive + 3);
    sort(leave, leave + 3);
}

/// Process ///
void solve(int testIndex){
    int car = 0, total = 0, i = 0, j = 0, temp = 0;

    while(i < 3 && j < 3){
        if(arrive[i] <= leave[j]){
            total += (arrive[i] - temp) * money[car];
            temp = arrive[i];
            car++;
            i++;
        }else{
            total += (leave[j] - temp) * money[car];
            temp = leave[j];
            car--;
            j++;
        }

        db(total);
    }

    while(j<3){
        total += (leave[j] - temp) * money[car];
        temp = leave[j];
        car--;
        j++;
        db(total);
    }

    cout << total << endl;
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
