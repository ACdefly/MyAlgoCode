/*
* @Author: wlun
* @Date:   2023-08-23 08:39:52
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-23 09:07:01
*/

#include <iostream>

using namespace std;

void solve()
{
    int n; cin >> n;
    int idx = 0;
    for(int i = 2; i <= n / i; i++)
    {
        if(n % i == 0) {
            while(n % i == 0) n /= i, idx++;
            cout << i << ' ' << idx << endl;
            idx = 0;
        }
    }
    if(n > 1) cout << n << ' ' << 1 << endl;
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
