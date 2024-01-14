/*
* @Author: wlun
* @Date:   2024-01-14 22:20:25
* @Last Modified by:   wlun
* @Last Modified time: 2024-01-14 22:48:22
*/

// 二进制优化
#include <iostream>
#include <vector>

const int N = 2010;

int f[N];

struct Good {
    int v, w;
};

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<Good> goods;
    for(int i = 0; i < n; i++) {
        int v, w, s; std::cin >> v >> w >> s;
        for(int k = 1; k <= s; k <<= 1) {
            goods.push_back({k * v, k * w});
            s -= k;
        }
        if(s > 0) goods.push_back({s * v, s * w});
    }
    for(auto &good : goods) {
        for(int j = m; j >= good.v; j--) {
            f[j] = std::max(f[j], f[j - good.v] + good.w);
        }
    }
    std::cout << f[m] << "\n";
    return 0;
}
