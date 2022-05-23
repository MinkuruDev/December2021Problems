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
#define MAX 100000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/// Global variable and input, init ///
vector<int> g[MAX];
int dis[MAX];
bool vis[MAX];
int n, c;
void inputAndInit(){
    cin >> n >> c;
    int x,y,z;
    while(c--){
        cin >> x >> y >> z;
        g[x].push_back(y);
        g[x].push_back(z);
    }
}

void bfs(int a){
    queue<int> q;
    q.push(a);
    dis[a] = 1;
    vis[a] = true;
    while(! q.empty()){
        int u = q.front();
        q.pop();
        repa(v, g[u]){
            if(vis[v]) continue;
            q.push(v);
            vis[v] = true;
            dis[v] = dis[u] + 1;
        }
    }
}

/// Process ///
void solve(int testIndex){
    bfs(1);
    rep(i,1,n){
        cout <<  dis[i] << endl;
    }
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
