/*
* @Author: wlun
* @Date:   2023-08-25 16:35:27
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-25 19:08:31
*/

#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N], f[N];
int q[N];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int len = 0;
    q[0] = -0x3f3f3f3f;
    for(int i = 0; i < n; i++) {
        int l = 0, r = len;
        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(q[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        len = max(len, r + 1);
        q[r + 1] = a[i];
        for(int i = 1; i <= n; i++) cout << q[i] << ' ';
        cout << endl;
    }
    cout << len << endl;
    return 0;
}
