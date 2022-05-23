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
int width, height, m, M;
double charWidth;
vector<int> word;
string s;
void inputAndInit(){
    cin >> width >> height;
    cin.ignore();
    getline(cin, s);
    M = 0;
    int cnt = 0;
    repa(si, s){
        if(si == ' '){
            if(cnt > M) M = cnt;
            word.push_back(cnt);
            cnt = 0;
        }else{
            cnt++;
        }
    }
    word.push_back(cnt);

}

bool check(double fontSize){
    int line = 1;
    charWidth = (2*fontSize)/3.0;
    double lineWidth = 0, newWidth = 0;

    lineWidth = charWidth * word[0];

    fow(i, 1, word.size()){

        newWidth = lineWidth + charWidth * (word[i] + 1);
        if(newWidth <= width){
            lineWidth = newWidth;
        }else{
            lineWidth = charWidth * word[i];
            line++;
        }
    }
    return line <= (height / fontSize);
}

/// Process ///
void solve(int testIndex){
    double high = (double)(width * 3) / (M * 2);
    double low = 0;
    double delta = 0.001;
    double mid;
    while(high - low > delta){
        mid = (low+high) / 2;
        if(check(mid)){
            low = mid;
        }else{
            high = mid;
        }
    }

    cout << mid << endl;
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
