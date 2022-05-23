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
#define MAX 50000

typedef long long ll;
using namespace std;

/// Global variable and input ///
int c[MAX],n,m,d,l;
void input(){
    cin >> n >> m >> d >> l;
    fow(i,0,n){
        cin >> c[i];
    }

    sort(c, c+n);
}

/// Process
void process(){
    int total = 0;
    int frt[m];
    fow(i,0,m) frt[i] = 0;

    fow(i,0,n){
        if((c[i] - (frt[total%m] * d)) < l) continue;

        frt[total%m]++;
        total++;
    }

    cout << total;
}

int main(){
    fast_io;
    input();
    process();
    return 0;
}
