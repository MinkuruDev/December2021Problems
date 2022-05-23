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
ll n,k,a[MAX],M;
void input(){
    M = 0;
    cin >> n >> k;
    fow(i,0,n){
        cin >> a[i];
        if(a[i] > M){
            M = a[i];
        }
    }

}

ll checkPlace(ll height, ll index){
    ll cnt = height - a[index];
    ll l = index, r = index;

    ll temp = height - 1;
    while(--l > 0){
        if(a[l] >= temp) break;

        cnt += temp - a[l];
        if(cnt > k) return -1;
        temp--;
    }
    if(l==0 && a[l] < temp) return -1;

    temp = height - 1;
    while (++r < n-1){
        if(a[r] >= temp) break;

        cnt += temp - a[r];
        if(cnt > k) return -1;
        temp--;
    }
    if(r==n-1 && a[r] < temp) return -1;

    return cnt;
}

void place(ll height, ll index){
    ll l = index, r = index;

    ll temp = height - 1;
    while(--l > 0){
        if(a[l] >= temp) break;

        a[l] = temp;
        temp--;
    }

    temp = height - 1;
    while (++r < n-1){
        if(a[r] >= temp) break;

        a[r] = temp;
        temp--;
    }
}

/// Process ///
void process(){
    while(true){
        int p = -1;
        ll minD = 1<<62;
        fow(i,1,n-1){
            ll d = checkPlace(M+1, i);
            if(d>0 && d<minD){
                minD = d;
                p = i;
            }
        }

        if(p < 0){
            cout << M << endl;
            break;
        }else{
            k -= minD;
            place(++M, p);
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
