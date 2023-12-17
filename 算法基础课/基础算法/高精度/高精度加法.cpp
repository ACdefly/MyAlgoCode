/*
* @Author: wlun
* @Date:   2023-07-27 21:50:53
* @Last Modified by:   wlun
* @Last Modified time: 2023-07-27 23:15:49
*/

#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> sum(std::vector<int>& A, std::vector<int>& B){
    std::vector<int> C{};
    int t = 0;
    for(int i = 0; i < A.size() || i < B.size(); i++){
        if(i < A.size()) t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    C.push_back(t);
    if(!t) C.pop_back();
    return C;
}

void solve() {
    std::string a, b;
    std::cin >> a >> b;
    std::vector<int> A{}, B{};
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    auto res = sum(A, B);
    for(int i = res.size() - 1; i >= 0; i--) std::cout << res[i];
    std::cout << std::endl;
}

int main()
{
    std::cin.tie(nullptr) -> sync_with_stdio(false);

    solve();

    return 0;
}

