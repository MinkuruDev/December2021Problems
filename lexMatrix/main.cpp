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
#define MAX 10000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

struct cell{
    int value;
    int rowIndex, colIndex;

    cell() = default;

    cell(int v, int r, int c){
        value = v;
        rowIndex = r;
        colIndex = c;
    }

    bool operator<(const cell other){
        return value < other.value;
    }

    bool operator==(const cell other){
        return value == other.value;
    }
};

bool const operator<(const vector<cell> &v1, const vector<cell> &v2){
    if(v1.size() != v2.size()) return v1.size() < v2.size();
    fow(i,0,v1.size()){
        if(v1[i].value == v2[i].value) continue;
        return v1[i].value < v2[i].value;
    }

    return false;
}

/// Global variable and input, init ///
vector<vector<cell>> cells;
vector<cell> vtm;
int n,m;
void inputAndInit(){
    cin >> n >> m;
    int t, M = 0;
    fow(i,0,n){
        vector<cell> vtt;
        fow(j,0,m){
            cin >> t;
            vtt.push_back(cell(t, i, j));
            if(t>M){
                vtm.clear();
                M = t;
                vtm.push_back(cell(t, i, j));
            }else if(t==M)
                vtm.push_back(cell(t, i, j));
        }
        cells.push_back(vtt);
    }

    vector<cell> vtM;
    repa(c, vtm){
        vector<cell> temp = cells[c.rowIndex];
        sort(temp.begin(), temp.end());
        reverse(temp.begin(), temp.end());
        if(vtM < temp) vtM = temp;
    }


    fow(i,0,n){
        vector<cell> vtt;
        fow(j,0,m){
            int ci = vtM[j].colIndex;
            vtt.push_back(cells[i][ci]);
        }
        cells[i] = vtt;
    }

    sort(cells.begin(), cells.end());
    reverse(cells.begin(), cells.end());

    vector<vector<cell>> cells1;
    fow(j,0,m){
        vector<cell> vtt;
        fow(i,0,n){
            vtt.push_back(cells[i][j]);
        }

        cells1.push_back(vtt);
    }
    sort(cells1.begin(), cells1.end());
    reverse(cells1.begin(), cells1.end());
    cells = cells1;

}

void printCells(){
    el;
    fow(i,0,n){
        fow(j,0,m){
            cout << cells[i][j].value << " ";
        }
        el;
    }
}

/// Process ///
void solve(int testIndex){
    //printCells();
    int a,b;
    cin >> a >> b;
    cout << cells[--b][--a].value << endl;
}

void test(){

}

int main(){
    fast_io;
    inputAndInit();
    //test();
    int testCase = 0;
    if(testCase == 0) cin >> testCase;

    fow(i,0,testCase)
        solve(i);
    return 0;
}
