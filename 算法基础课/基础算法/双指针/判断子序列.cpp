/*
* @Author: wlun
* @Date:   2023-08-02 20:12:44
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-02 20:19:20
*/
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n; i++) std::cin >> a[i];
    for(int i = 0; i < m; i++) std::cin >> b[i];
    int i = 0, j = 0;
    while(i < n && j < m){
        if(a[i] == b[j]){
            i++;
            if(i == n){
                std::cout <<"Yes\n";
                return;
            }
        }
        j++;
    }
    std::cout << "No\n";
}

int main()
{
    std::cin.tie(nullptr) -> sync_with_stdio(false);

    solve();

    return 0;
}
