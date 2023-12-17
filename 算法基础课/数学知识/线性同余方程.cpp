/*
* @Author: wlun
* @Date:   2023-08-25 09:06:18
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-25 09:21:49
*/
#include <iostream>
#define int long long
using namespace std;

int exgcd(int a, int b, int &x, int &y)
{
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, x, y, m;
        cin >> a >> b >> m;
       int d = exgcd(a, m, x, y);
       if (b % d) puts("impossible");
       else cout << b / d * x % m << endl;
    }
    return 0;
}
