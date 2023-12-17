/*
* @Author: wlun
* @Date:   2023-07-27 14:04:16
* @Last Modified by:   wlun
* @Last Modified time: 2023-07-27 14:11:43
*/

#include <bits/stdc++.h>
#define eps 1e-8
using i64 = long long;

void solve() {
    double n;
    std::cin >> n;
    double l = -10010, r = 10010;
    while(r - l >= eps){
        double mid = (l + r) / 2;
        if(mid * mid * mid >= n) r = mid;
        else l = mid;
    }
    printf("%.6lf\n", l);
}

int main()
{

    solve();

    return 0;
}
