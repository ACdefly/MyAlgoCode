/*
* @Author: wlun
* @Date:   2023-08-02 21:09:36
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-02 21:22:03
*/
#include <bits/stdc++.h>

using i64 = long long;
const int N = 100010;
int presum[N], nums[N];

void insert(int l, int r, int c){
    nums[l] += c, nums[r + 1] -= c;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    presum[0] = 0;
    for(int i = 1; i <= n; i++)
        std::cin >> presum[i], nums[i] = presum[i] - presum[i - 1];
    while(m--){
        int l, r, c;
        std::cin >> l >> r >> c;
        insert(l, r, c);
    }
    for(int i = 1; i <= n; i++){
         nums[i] += nums[i - 1];
    }
    for(int i = 1; i <= n; i++) std::cout << nums[i] << ' ';
}

int main()
{
    std::cin.tie(nullptr) -> sync_with_stdio(false);

    solve();

    return 0;
}
