/*
* @Author: wlun
* @Date:   2023-08-24 15:40:00
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-24 15:42:53
*/
#include <iostream>
#define int long long
using namespace std;

int quick_power(int a, int b, int p)
{
    int ans = 1;
    ans %= p;
    while(b)
    {
        if(b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

signed main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int a, p;
        cin >> a >> p;
        if(a % p) cout << quick_power(a, p - 2, p) << endl;
        else cout << "impossible\n";
    }
    return 0;
}
