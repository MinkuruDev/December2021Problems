#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fow(i,a,b) for(auto i = a; i<b; i++)
#define rep(i,a,b) for(auto i = a; i<=b; i++)
#define red(i,a,b) for(auto i = a; i>=b; i--)
#define repa(i,a) for(auto i: a)
#define vti vector<int>
#define db(x) cout << #x << " = " << x << endl
#define el cout << endl
#define getBit(n,i) ((n>>i)&1)
#define MAX 10000
#define mod 1000000007

typedef long long ll;
using namespace std;

/// Global variable and input ///
map<int, ll> mii;
map<int, vti> ap;
bool prime[] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0};
void input(){
    // init
    rep(i,1,9){
        rep(j,1,9){
            if(prime[i+j]){
                ap[i].push_back(j);
                //cout << i << j << endl;
            }
        }
    }


}

/// Process ///
void process(){
    int n;
    cin >> n;
    if(n==1) {
        cout << 4 << endl;
        return;
    }

    mii.clear();
    rep(i,1,9){
        repa(j,ap[i]){
            mii[j]++;
        }
    }
    ll sum = 4;

    while(--n){
        map<int, ll> temp;
        rep(i,1,9){
            repa(j,ap[i]){
                temp[j] += mii[i];
                //cout << i << j << endl;
            }

            sum += mii[i]%mod;
        }

        mii = temp;
    }

    cout << sum%mod << endl;
}

void test(){

}

int main(){
    fast_io;
    input();
    //test();
    int testCase;
    cin >> testCase;
    while(testCase--)
        process();
    return 0;
}
