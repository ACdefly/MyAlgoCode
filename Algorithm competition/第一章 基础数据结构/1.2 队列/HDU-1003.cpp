#include <iostream>
#define inf 0x3f3f3f3f
using namespace std;

const int N = 1e5 + 10;

int a[N];

void solve()
{
  int n;
  cin >> n;
  int mn = 0, mx = -inf;
  a[0] = 0;
  int i1, i2;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
    if(a[i] - mn > mx) mx = a[i] - mn, i2 = i;
    if(a[i] < mn) mn = a[i];
  }
  i1 = i2;
  for(int i = 1; i <= i2; i++) {
      if(mx == a[i2] - a[i - 1]) {
          i1 = i;
          break;
      }
  }
  printf("%d %d %d\n", mx, i1, i2);
}

// Case 1:
// 14 1 4
// 
// Case 2:
// 7 1 6

int main()
{
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++)
  {
      printf("Case %d:\n", i);
      solve();
      if(i != t) printf("\n");
  }
  return 0;
}