/*
* @Author: wlun
* @Date:   2023-07-27 13:08:30
* @Last Modified by:   wlun
* @Last Modified time: 2023-07-27 13:21:05
*/

#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 10;
int q[N], tmp[N];

void merge_sort(int *q, int l, int r){
    if(l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
    int i = l, j = mid + 1, ans = 0;
    while(i <= mid && j <= r){
        if(q[i] <= q[j]) tmp[ans++] = q[i++];
        else tmp[ans++] = q[j++];
    }
    while(i <= mid) tmp[ans++] = q[i++];
    while(j <= r) tmp[ans++] = q[j++];
    for(int i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
}


void solve() {
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) std::cin >> q[i];
    merge_sort(q, 0, n - 1);
    for(int i = 0; i < n; i++) std::cout << q[i] << ' ';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
