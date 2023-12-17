/*
* @Author: wlun
* @Date:   2023-08-24 12:14:21
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-24 12:20:58
*/

#include <iostream>

using namespace std;

int solve(int x)
{
    int res = x;
    for(int i = 2; i <= x / i; i++)
    {
        if(x % i == 0) {
            res = res / i * (i - 1);
            while(x % i == 0) x /= i;
        }
    }
    if(x > 1) res = res / x * (x - 1);
    return res;
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        cout << solve(x) << endl;
    }
    return 0;
}
