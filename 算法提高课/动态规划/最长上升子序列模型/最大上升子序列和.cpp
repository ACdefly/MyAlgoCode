/*
* @Author: wlun
* @Date:   2024-01-06 23:33:00
* @Last Modified by:   wlun
* @Last Modified time: 2024-01-06 23:39:37
*/
#include <iostream>

using namespace std;

const int N = 1010;

int a[N], f[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        f[i] = a[i];
        for(int j = 1; j < i; j++) {
            if(a[j] < a[i]) f[i] = max(f[i], f[j] + a[i]);
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++) res = max(res, f[i]);
    cout << res << endl;
    return 0;
}
