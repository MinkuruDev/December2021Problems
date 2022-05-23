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
using namespace std;

/// Global variable and input ///

void input(){

}

/// Process ///
void process(){
    while(true){
        map<string, bool> msb;
        msb.clear();
        int l,r,k;
        cin >> l >> r >> k;
        int lk = ceil((float)l/k);
        int rk = r/k;
        if(lk>rk){
            cout << -1 << endl;
        }
        rep(i,lk,rk){
            string s = to_string(i*k);
            msb[s] = true;
        }

        repa(it, msb){
            cout << it.first << endl;
            break;
        }

    }
}

void test(){
    vector<int> db;
    int temp;
    while(true){
        scanf("%d", &temp);
        if(temp == '\n') break;
        db.push_back(temp);
        db(temp);
    }
}

int main(){
    fast_io;
    input();
    test();
    int testCase = 1;
    if(testCase == 0) cin >> testCase;
    while(testCase--);
        //process();
    return 0;
}
