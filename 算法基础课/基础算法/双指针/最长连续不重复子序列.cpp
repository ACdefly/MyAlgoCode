/*
* @Author: wlun
* @Date:   2023-08-02 19:55:04
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-02 20:00:24
*/

#include <bits/stdc++.h>

using i64 = long long;

const int N = 100010;
int a[N], mp[N];

void solve() {
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) std::cin >> a[i];
    int ans = 0;
    memset(mp, 0, sizeof mp);
    for(int i = 0, j = 0; i < n; i++){
        mp[a[i]]++;
        while(mp[a[i]] > 1){
            mp[a[j++]]--;
        }
        ans = std::max(ans, i - j + 1);
    }
    std::cout << ans << std::endl;
}

int main()
{
    std::cin.tie(nullptr) -> sync_with_stdio(false);

    solve();

    return 0;
}
