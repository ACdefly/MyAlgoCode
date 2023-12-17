/*
* @Author: wlun
* @Date:   2023-08-23 09:08:03
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-23 09:39:00
*/
#include <iostream>

using namespace std;
const int N = 1e6 + 10;
bool st[N];

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 2; i <= n; i++)
    {
        if(!st[i]) {
            ans++;
            for(int j = i + i; j <= n; j += i) st[j] = true;
        }
    }
    cout << ans << endl;
    return 0;
}
