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
map<int, set<int>> misi;
map<int, bool> seated;
void inputAndInit(){

}

int detectCycle(int a){
    seated[a] = true;
    auto b = *(misi[a].begin());
    misi.erase(a);
    seated[b] = true;
    int sz = 2;
    int next = -1;
    repa(i, misi[b]){
        if(i!=a){
            next = i;
            seated[next] = true;
            sz++;
        }
    }
    misi.erase(b);

    if(next < 0) return -1;
    int prev = next;
    while(true){
        repa(i,misi[prev]){
            if(i==a) return sz;
            if(seated[i]) continue;
            next = i;
            sz++;
            seated[i] = true;
        }
        misi.erase(prev);

        if(next == prev) break;
        prev = next;
    }

    return -1;
}

/// Process ///
void solve(int testIndex){
    misi.clear();
    seated.clear();
    int n,k,a,b;
    cin >> n >> k;
    while(k--){
        cin >> a >> b;
        misi[a].insert(b);
        misi[b].insert(a);
        if(misi[a].size() > 2 || misi[b].size() > 2){
            cout << "N" << endl;
            return;
        }
    }

    while(! misi.empty()){
        auto a = *misi.begin();
        if(a.first <= 0) break;
        int c = detectCycle(a.first);
        if(c>0){
            if(c == n){
                cout << "Y" << endl;
            }else{
                cout << "N" << endl;
            }
            return;
        }
    }

    cout << "Y" << endl;
}

void test(){

}

int main(){
    fast_io;
    inputAndInit();
    test();
    int testCase = 0;
    if(testCase == 0) cin >> testCase;
    fow(i,0,testCase)
        solve(i);
    return 0;
}
