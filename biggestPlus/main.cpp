#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fow(i,a,b) for(auto i = a; i<b; i++)
#define rep(i,a,b) for(auto i = a; i<=b; i++)
#define red(i,a,b) for(auto i = a; i>=b; i--)
#define repa(i,a) for(auto i: a)
#define db(x) cout << #x << " = " << x << endl
#define el cout << endl
#define getBit(n,i) ((n>>i)&1)
#define MAX 5000

typedef long long ll;
using namespace std;

struct PixelCount{
    int index, cnt;

    PixelCount(){
        index = 0;
        cnt = 0;
    }

    bool operator<(const PixelCount other){
        if(cnt == other.cnt)
            return index > other.index;
        return cnt < other.cnt;
    }
};

/// Global variable and input ///
bool pixel[MAX][MAX];
PixelCount pixelRowCount[MAX], pixelColCount[MAX];
int rows,cols;
void input(){
    cin >> rows >> cols;

    fow(j,0,cols){
        pixelColCount[j].index = j;
    }

    fow(i,0,rows){
        int cnt = 0;
        pixelRowCount[i].index = i;
        string s;
        cin >> s;

        fow(j,0,cols){
            if(s[j] == '1'){
                cnt++;
                pixelColCount[j].cnt++;
                pixel[i][j] = 1;
            }else{
                pixel[i][j] = 0;
            }
        }

        pixelRowCount[i].cnt = cnt;
    }

    sort(pixelColCount, pixelColCount + cols);
    reverse(pixelColCount, pixelColCount + cols);
    sort(pixelRowCount, pixelRowCount + rows);
    reverse(pixelRowCount, pixelRowCount + rows);
}

int checkPlusSign(int x, int y){
    if(!pixel[x][y]) return 0;
    int sz = 1;
    while(true){
        if(x-sz<0 || y-sz<0 || x+sz>=cols || y+sz>=rows) return sz-1;
        if(pixel[x-sz][y] && pixel[x+sz][y]
           && pixel[x][y-sz] && pixel[x][y+sz]) sz++;
        else
            return sz-1;
    }
}

/// Process ///
void process(){
    if(pixelColCount[0].cnt < 3 || pixelRowCount[0].cnt < 3){
        cout << -1;
        return;
    }

    int r3 = 0, c3 = 0;
    red(i,rows-1,0){
        if(pixelRowCount[i].cnt >= 3){
            r3 = i;
            break;
        }
    }
    red(i,cols-1,0){
        if(pixelColCount[i].cnt >= 3){
            c3 = i;
            break;
        }
    }
    //db(r3);db(c3);

    int M = 0, x = 0, y = 0;
    rep(i,0,r3){
        if(pixelRowCount[i].cnt <= M*2+1) break;
        rep(j,0,c3){
            if(pixelColCount[j].cnt <= M*2+1) break;
            int s = checkPlusSign(pixelRowCount[i].index,pixelColCount[j].index);
            //db(s);db(pixelColCount[j].index); db(pixelRowCount[i].index); el;
            if(s>M){
                M = s;
                x = pixelColCount[j].index;
                y = pixelRowCount[i].index;
            }
        }
    }

    if(M>0){
        cout << M*4+1 << endl;
        cout << y+1 << " " << x+1<< endl;
    }else{
        cout << -1 << endl;
    }
}

void test(){
    el;
    fow(i,0,cols){
        cout << pixelColCount[i].index << " " << pixelColCount[i].cnt << endl;
    }
    el;
    fow(i,0,rows){
        cout << pixelRowCount[i].index << " " << pixelRowCount[i].cnt << endl;
    }
    el;
    fow(i,0,rows){
        fow(j,0,cols){
            cout << pixel[i][j] << " ";
        }
        el;
    }
}

int main(){
    fast_io;
    input();
    //test();
    process();
    return 0;
}
