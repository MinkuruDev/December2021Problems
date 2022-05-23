#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define vti vector<int>
#define vtv vector<vti>
#define msi map<string, int>
#define fow(i,a,b) for(auto i = a; i<b; i++)
#define rep(i,a,b) for(auto i = a; i<=b; i++)
#define red(i,a,b) for(auto i = a; i>=b; i++)
#define repa(i,o) for(auto i: o)
#define db(x) cout << #x << " = " << x << endl;
#define getBit(n,i) ((n>>i)&1)
#define MAX 10000

typedef long long ll;
using namespace std;

/// Global variable and input ///
map<string, string> mss;
map<string, bool> msb;
void input(){

}

/// Process ///
void process(){
    int testCase;
    cin >> testCase;

    rep(i,1,testCase){
        int n;
        cin >> n;
        mss.clear();
        msb.clear();

        fow(j,1,n){
            string s1,s2;
            cin >> s1 >> s2;
            mss[s1] = s2;

            if(msb[s1]){
                msb.erase(s1);
            }else{
                msb[s1] = true;
            }
            if(msb[s2]){
                msb.erase(s2);
            }else{
                msb[s2] = true;
            }
        }

        string head = "";
        repa(it, msb){
            if(mss[it.first] != "") head = it.first;
        }

        cout << "Scenario #" << i << ":" << endl;
        while(head != ""){
            cout << head << endl;
            head = mss[head];
        }

        cout << endl;
    }
}

void test(){

}

int main(){
    fast_io;
    input();
    //test();
    process();
    return 0;
}
