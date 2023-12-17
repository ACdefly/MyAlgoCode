/*
* @Author: wlun
* @Date:   2023-08-02 16:21:22
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-02 16:25:47
*/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 10;

std::vector<int> vec(N, 0);

void solve() {
    int n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) std::cin >> vec[i];
    for(int i = 1; i <= n; i++) vec[i] += vec[i - 1];
    while(m--){
        int l, r;
        std::cin >> l >> r;
        std::cout << vec[r] - vec[l - 1] << std::endl;
    }
}

int main()
{
    std::cin.tie(nullptr) -> sync_with_stdio(false);

    solve();

    return 0;
}
