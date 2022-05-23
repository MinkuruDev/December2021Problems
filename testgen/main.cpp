//vucuongcpp
#include <bits/stdc++.h>
#define nmax 1
#define vti vector<int>
#define pii pair<int, int>
#define vtp vector<pii>
#define vtv vector<vti>
#define PB push_back
#define MP make_pair
#define M map<int,string>
#define F first
#define S second
#define oo 1000000009
#define Task ""
#define reset(f) memset(f, 0, sizeof f)

using namespace std;
bool check;
int main()
{
//    freopen(Task".INP", "r", stdin);
//    freopen(Task".OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int myints[n];
    for (int i =0; i<n; i++)
    {
        cin >> myints[i];
    }
  while(next_permutation(myints,myints+n))
  {
      check=true;
      for(int i=1; i<n-1; i++)
      {
          if ((myints[i] - myints[i-1] ) * (myints[i] - myints[i+1]) < 0)
          {
              check=false;
              break;
          }

      }

      if (check==true)
       {
        for (int i =0; i<n; i++)
        cout  <<  myints[i] << " ";
        exit(0);
        }
  }
    sort(myints,myints+n);

    while(next_permutation(myints,myints+n))
  {
      check=true;
      for(int i=1; i<n-1; i++)
      {
          if ((myints[i] - myints[i-1] ) * (myints[i] - myints[i+1]) < 0)
          {
              check=false;
              break;
          }

      }
      if (check==true)
       {
        for (int i =0; i<n; i++)
        cout  <<  myints[i] << " ";
        exit(0);
        }
  }
  return 0;
}
