/*
* @Author: wlun
* @Date:   2023-07-27 13:55:14
* @Last Modified by:   wlun
* @Last Modified time: 2023-07-27 14:02:12
*/

#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 10;
int a[N];
int n, q;

int low_binary(int x){
    int l = 0, r = n - 1;
    while(l < r){
        int mid = l + r >> 1;
        if(a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int up_binary(int x){
    int l = 0, r = n - 1;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(a[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return l;
}

void solve() {
    
    std::cin >> n >> q;
    for(int i = 0 ; i < n; i++) std::cin >> a[i];
    while(q--){
        int x;
        std::cin >> x;
        int l = low_binary(x);
        if(a[l] != x) {
            std::cout << "-1 -1" << std::endl;
            continue;
        }
        int r = up_binary(x);
        std::cout << l <<' ' << r << std::endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
