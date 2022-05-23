#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fow(i,a,b) for(auto i = a; i<b; i++)
#define rep(i,a,b) for(auto i = a; i<=b; i++)
#define red(i,a,b) for(auto i = a; i>=b; i++)
#define repa(i,a) for(auto i: a)
#define db(x) cout << #x << " = " << x << endl
#define el cout << endl
#define getBit(n,i) ((n>>i)&1)
#define MAX 10000

typedef long long ll;
using namespace std;

/// Global variable and input ///
int bit[32], bitEven[32];
int n, bigBit = 0;
ll sum = 0;
string opr;
void input(){
    fow(i,0,32){
        bit[i] = 0;
    }

    cin >> n;
    int temp;
    fow(i,0,n){
        cin >> temp;
        sum += temp;
        string bin = bitset<32>(temp).to_string();
        reverse(bin.begin(), bin.end());
        auto l = bin.length();

        fow(i,0,l){
            if(bin[i] == '1'){
                bit[i]++;
                if(i > bigBit)
                    bigBit = i;
            }
        }
    }

    cin >> opr;
}

/// Process ///
void process(){
    int testCase = 1;
    if(testCase <= 0) cin >> testCase;
    while(testCase--){
        auto l = opr.length();
        fow(i,0,l){
            if(opr[i] == '1'){
                sum -= bit[0];
                bit[0] = 0;
            }else{
                temp = n - bit[0];
                bit[0] += bit[1];
                sum -= bit[1];

                fow(i,1,bigBit){
                    bit[i] = bit[i+1];
                    sum -= bit[i]*pow(2,i-1);
                }
            }

            cout << sum << endl;
        }
    }
}

void test(){
    fow(i,0,32){
        cout << bit[i] << " ";

    }
    cout << sum;
}

int main(){
    fast_io;
    input();
    test();
    //process();
    return 0;
}
