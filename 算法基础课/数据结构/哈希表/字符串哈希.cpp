/*
* @Author: wlun
* @Date:   2023-08-08 23:53:33
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-09 00:00:53
*/

#include <iostream>

using ull = unsigned long long;
const int N = 1e5 + 10, P = 131;
char str[N];
ull h[N], p[N];

ull find(int l, int r){
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
    int n, m;
    std::cin >> n >> m >> (str + 1);
    p[0] = 1;
    for(int i = 1; i <= n; i++){
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }
    while(m--){
        int l1, r1, l2, r2;
        std::cin >> l1 >> r1 >> l2 >> r2;
        std::cout << (find(l1, r1) == find(l2, r2) ? "Yes" : "No") << "\n";
    }
    return 0;
}
