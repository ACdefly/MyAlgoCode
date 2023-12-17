/*
 * @Author: wlun
 * @Date:   2023-07-27 12:38:44
 * @Last Modified by:   wlun
 * @Last Modified time: 2023-07-27 13:06:17
 */
#include <bits/stdc++.h>

constexpr int N = 1e5 + 10;
int q[N];

void quick_sort(int q[], int l, int r){
    if(l >= r) return;
    int mid = (l + r) >> 1;
    int i = l - 1, j = r + 1, x = q[mid];
    while(i < j){
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) std::swap(q[i], q[j]);
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::cin >> q[i];
    }
    quick_sort(q, 0, n - 1);
    for(int i = 0; i < n; i++) std::cout << q[i] << ' ';
    return 0;
}
