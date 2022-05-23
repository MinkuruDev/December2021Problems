#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fow(i,a,b) for(auto i = a; i<b; i++)
#define rep(i,a,b) for(auto i = a; i<=b; i++)
#define red(i,a,b) for(auto i = a; i>=b; i++)
#define repa(i,a) for(auto i: a)
#define db(x) cout << #x << " = " << x << endl
#define el cout << endl
#define getBit(n,i) ((n>>i)&1)
#define MAX 1000

typedef long long ll;
using namespace std;

int wValue = 6;
int sValue = 4;
int vValue = 5;

struct Block{
    int w,s;
    ll v;

    bool operator<(const Block other){
        return (w*wValue + s*sValue +v*vValue) < (other.w*wValue + other.s*sValue + other.v*vValue);
        //return s < other.s;
    }

    Block operator+(const Block other){
        Block result;
        result.w = w + other.w;
        result.v = v + other.v;
        result.s = min(other.s, s - other.w);

        return result;
    }
};

/// Global variable and input ///
int n;
Block blocks[MAX];
void input(){
    cin >> n;
    fow(i,0,n){
        cin >> blocks[i].w >> blocks[i].s >> blocks[i].v;
    }

}

/// Process ///
void process(){
    int testCase = 1;
    if(testCase <= 0) cin >> testCase;
    while(testCase--){

    }
}

void test(){
    el;
    fow(i,0,n){
        printf("%d %d %d\n", blocks[i].w, blocks[i].s, blocks[i].v);
    }
    el;


    int range = 100000;
    ll cnt = 0;
    while(true){
    sValue = rand()%range;
    wValue = rand()%range;
    vValue = rand()%range;

    if(++cnt%range == 0) db(cnt);

    sort(blocks, blocks+n);
    Block block = blocks[0], temp;

    fow(i,1,n){
        temp = block + blocks[i];
        if(temp.s >= 0){
            block = temp;
            //cout << i << " ";
        }
    }

            if(block.v==22){
                db(sValue); db(wValue); db(vValue);
                return;
            }


    }


}

int main(){
    fast_io;
    input();
    test();
    //process();
    return 0;
}
