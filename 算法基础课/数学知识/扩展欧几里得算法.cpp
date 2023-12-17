/*
* @Author: wlun
* @Date:   2023-08-25 08:28:34
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-25 09:18:44
*/

#include <iostream>

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

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, x, y;
        cin >> a >> b;
        exgcd(a, b, x, y);
        cout << x << ' ' << y << endl;
    }
    return 0;
}
