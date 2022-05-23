#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define vti vector<int>
#define vtv vector<vti>
#define msi map<string, int>
#define fow(i,a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<=b; i++)
#define red(i,a,b) for(int i = a; i>=b; i++)
#define db(x) cout << #x << " = " << x << endl;
#define getBit(n,i) ((n>>i)&1)
#define MAX 10000

typedef long long ll;
using namespace std;

/// Global variable and input ///
int a[1000],b[1000],c[1000];
int n;
void input(){
    cin >> n;
    fow(i,0,n){
        cin >> a[i];
    }
    fow(i,0,n){
        cin >> b[i];
        c[i] = b[i] - a[i];
    }
}

/// Process
void process(){
    int previous = abs(c[0]);
    int sum = previous;
    fow(i,1,n){
        if(c[i-1] * c[i] > 0){
            if(abs(c[i]) <= previous)
                previous = abs(c[i]);
            else{
                sum += abs(c[i]) - previous;
                previous = abs(c[i]);
            }
        }else{
            previous = abs(c[i]);
            sum += previous;
        }
    }

    cout << sum;
}

int main(){
    fast_io;
    input();
    process();
    return 0;
}
