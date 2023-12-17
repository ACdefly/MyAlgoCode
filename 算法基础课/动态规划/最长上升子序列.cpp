/*
* @Author: wlun
* @Date:   2023-08-25 16:25:05
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-25 16:36:17
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
    for(int i = 1; i <= n; i++) {
        f[i] = 1;
        for(int j = 1; j <= i; j++) {
            if(a[j] < a[i]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, f[i]);
    cout << ans << endl;
    return 0;
}
