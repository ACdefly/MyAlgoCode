/*
* @Author: wlun
* @Date:   2023-08-23 22:45:06
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-23 22:53:43
*/

#include <iostream>

using namespace std;

int gcd(int p, int q) {
    return q == 0 ? p : gcd(q, p % q);
}

int main()
{
    int n;
    cin >> n;
    while(n--) {
        int p, q;
        cin >> p >> q;
        cout << gcd(p, q) << endl;
    }
    return 0;
}
