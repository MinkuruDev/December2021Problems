#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fow(i,a,b) for(auto i = a; i<b; i++)
#define rep(i,a,b) for(auto i = a; i<=b; i++)
#define red(i,a,b) for(auto i = a; i>=b; i--)
#define repa(i,a) for(auto i: a)
#define db(x) cout << #x << " = " << x << endl
#define el cout << endl
#define getBit(n,i) ((n>>i)&1)
#define mod = 1000000007
#define MAX 500000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

struct Node{
    map<char, int> mci;

    Node() = default;

    Node operator+(const Node other){
        if(other.mci.size() == 0) return *this;
        if(mci.size() == 0) return other;
        Node result = *this;
        repa(it, other.mci){
            result.mci[it.first] += it.second;
        }
        return result;
    }
};

/// Global variable and input ///
Node st[MAX*4];
string buildStr;
int n,q;

void buildTree(int id, int l, int h){
    if(l==h){
        st[id].mci[buildStr[l]] = 1;
        return;
    }

    int m = (l + h) >> 1;
    int id2 = id << 1;
    buildTree(id2, l, m);
    buildTree(id2+1, m+1, h);

    st[id] = st[id2] + st[id2+1];
}

void input(){
    cin >> n >> buildStr >> q;
    buildStr = " " + buildStr;

    buildTree(1,1,n);
}

void update(int id, int l, int h, int i, char v){
    if(i < l || i > h) return;

    st[id].mci[v]++;
    if(--st[id].mci[buildStr[i]] == 0) st[id].mci.erase(buildStr[i]);

    if(l == h){
        swap(buildStr[i], v);
        return;
    }

    int m = (l + h) >> 1;
    int id2 = id << 1;
    update(id2, l, m, i, v);
    update(id2+1, m+1, h, i, v);
}

Node get(int id, int l, int h, int left, int right){
    if(right < l || left > h) return Node();

    if(l>=left && h <=right) return st[id];

    int m = (l + h) >> 1;
    int id2 = id << 1;

    return get(id2, l, m, left, right) + get(id2+1, m+1, h, left, right);
}

void printTree(int id, int l, int h){
    if(l == h){
        cout << st[id].mci.size() << " ";
        return;
    }

    int m = (l + h) >> 1;
    int id2 = id << 1;

    printTree(id2, l, m);
    printTree(id2+1, m+1, h);
}

/// Process ///
void process(){
    //printTree(1,1,n);
    while(q--){
        int o,l;
        cin >> o >> l;
        if(o == 1){
            char c; cin >> c;
            if(c==buildStr[l]) continue;
            update(1,1,n,l,c);
        }else{
            int r; cin >> r;
            cout << get(1,1,n,l,r).mci.size() << endl;
        }
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
