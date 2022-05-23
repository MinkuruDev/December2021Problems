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

struct Point{
    int x,y;

    Point() = default;

    Point(int a, int b){
        x = a;
        y = b;
    }
};

/// Global variable and input ///
vector<string> vts;
vector<Point> vtp[26];
int n,m,q;
void input(){
    cin >> n >> m >> q;
    string s;
    fow(i,0,n){
        cin >> s;
        vts.push_back(s);
        fow(j,0,m){
            vtp[s[j]-'a'].push_back(Point(i,j));
        }
    }
}

bool searchString(string s, int i, int x, int y, int dx, int dy){
    //db(s);
    if(i == s.size()) return true;
    if(dx==0 && dy==0){
        rep(j,-1,1){
            rep(k,-1,1){
                if(j==0 && k==0) continue;
                bool res = searchString(s,i+1,x,y,j,k);
                if(res) return true;
            }
        }
    }else{
        x+=dx;
        y+=dy;
        if(x>=n || y>=m || x<0 || y<0) return false;
        if(vts[x][y] == s[i]){
            return searchString(s,i+1,x,y,dx,dy);
        }
    }

    return false;
}

/// Process ///
void process(){
    string query;
    fow(i,0,q){
        bool flag = false;
        cin >> query;
        repa(p, vtp[query[0] - 'a']){
            if(searchString(query,0,p.x,p.y,0,0)){
                flag = true;
                break;
            }
        }
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
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
