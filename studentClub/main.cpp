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
using namespace std;

/// Global variable and input ///
vector<int> g[MAX];
bool visited[MAX];
map<int, bool> mib;
ll factorial[MAX];
int n,m;
void input(){
    cin >> n >> m;
    int a,b;
    fow(i,0,m){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        mib[a] = true;
        mib[b] = true;
    }

    factorial[0] = 1;
    fow(i,1,m+1){
        factorial[i] = i * factorial[i-1];
        factorial[i] %= mod;
    }

    //cout << "input done" << endl;
}

vector<int> bfs(){
    vector<int> result;

    while(mib.size() != 0){
        auto cur = mib.begin();
        mib.erase(cur);
        int sz = 1;
        queue<int> q;
        q.push((*cur).first);
        visited[(*cur).first] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            repa(v,g[u]){
                if(visited[v]) continue;
                q.push(v);
                visited[v] = true;
                mib.erase(v);
                sz++;
            }
        }

        if(sz > 2) result.push_back(sz);
    }

    return result;
}

/// Process ///
void process(){
    auto v = bfs();
    ll strength = 0;
    repa(i,v){
        strength += factorial[i];
    }

    cout << strength%mod << endl;
}

void test(){

}

int main(){
    fast_io;
    input();
    //test();
    int testCase = 1;
    if(testCase == 0) cin >> testCase;
    while(testCase--)
        process();
    return 0;
}
