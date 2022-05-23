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
#define mod 1000000007
#define MAX 10000

typedef long long ll;
using namespace std;
using type = ll;

struct Matrix {
    vector <vector <type> > data;

    int row() const { return data.size(); }

    int col() const { return data[0].size(); }

    auto & operator [] (int i) { return data[i]; }

    const auto & operator[] (int i) const { return data[i]; }

    Matrix() = default;

    Matrix(int r, int c): data(r, vector <type> (c)) { }

    Matrix(const vector <vector <type> > &d): data(d) {

        /**/ assert(d.size());
        /**/ int size = d[0].size();
        /**/ assert(size);
        /**/ for (auto x : d) assert(x.size() == size);
    }

    friend ostream & operator << (ostream &out, const Matrix &d) {
        for (auto x : d.data) {
            for (auto y : x) out << y << ' ';
            out << '\n';
        }
        return out;
    }

    static Matrix identity(long long n) {
        Matrix a = Matrix(n, n);
        while (n--) a[n][n] = 1;
        return a;
    }

    Matrix operator * (const Matrix &b) {
        Matrix a = *this;

        assert(a.col() == b.row());

        Matrix c(a.row(), b.col());
        for (int i = 0; i < a.row(); ++i)
            for (int j = 0; j < b.col(); ++j)
                for (int k = 0; k < a.col(); ++k)
                    c[i][j] += (a[i][k] * b[k][j]) % mod;
        return c;
    }

    Matrix pow(long long exp) {

        assert(row() == col());

        Matrix base = *this, ans = identity(row());
        for (; exp > 0; exp >>= 1, base = base * base)
            if (exp & 1) ans = ans * base;
        return ans;
    }
};


/// Global variable and input ///

void input(){

}

/// Process ///
void process(){
    int n;
    cin >> n;
    if(n==1){
        cout << 19;
        return;
    }
    Matrix a({
        {2},
        {1},
        {5},
        {18}
    });

    Matrix b({
        {2,1,5,18}
    });
    ll result;
    Matrix c = a * b;
    c = c.pow(n/2);
    if(n&1){ // n%2 == 1
        c = b * c;
        cout << c;
        result = c[0][2] + c[0][3];
    }else{
        cout << c;
        result =  c[0][1] + c[0][2]
                + c[1][1] + c[1][3]
                + c[2][1] + c[2][2]
                + c[3][1] + c[3][3];
    }

    cout << result % mod;
}

void test(){
    Matrix a({
        {2},
        {1},
        {5},
        {18}
    });

    Matrix c({
        {2,1,5,18}
    });

    auto b = a * c;
    cout << c * b;
}

int main(){
    fast_io;
    input();
    //test();
    process();
    return 0;
}
