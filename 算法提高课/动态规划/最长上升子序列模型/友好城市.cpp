/*
* @Author: wlun
* @Date:   2024-01-06 23:14:31
* @Last Modified by:   wlun
* @Last Modified time: 2024-01-06 23:22:08
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5010;
struct Node{
    int l, r;
}node[N];
int f[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> node[i].l >> node[i].r;
    sort(node + 1, node + (n + 1), [&](Node &a, Node &b) {
        return a.l < b.l;
    });
    for(int i = 1; i <= n; i++) {
        f[i] = 1;
        for(int j = 1; j < i; j++) {
            if(node[j].r < node[i].r) f[i] = max(f[i], f[j] + 1);
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++) res = max(res, f[i]);
    cout << res << endl;
    return 0;
}
