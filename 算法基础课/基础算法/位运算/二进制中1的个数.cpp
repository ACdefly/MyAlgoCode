/*
* @Author: wlun
* @Date:   2023-08-02 20:57:58
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-02 21:01:16
*/

#include <bits/stdc++.h>
#define lowbit(x) (x & (-x))
using i64 = long long;

void solve() {
    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;
        int ans = 0;
        while(lowbit(n)){
            ans++;
            n -= lowbit(n);
        }
        std::cout << ans << ' ';
    }
}

int main()
{
    std::cin.tie(nullptr) -> sync_with_stdio(false);

    solve();

    return 0;
}
