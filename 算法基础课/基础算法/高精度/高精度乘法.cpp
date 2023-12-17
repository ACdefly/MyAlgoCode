/*
* @Author: wlun
* @Date:   2023-08-07 13:24:26
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-09 15:35:28
*/

#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> mul(std::vector<int>& A, std::vector<int>& B){
    std::vector<int> res(A.size() + B.size() + 10, 0);
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < B.size(); j++){
            res[i + j] += A[i] * B[j];
        }
    }
    int t = 0;
    for(int i = 0; i < res.size(); i++){
        res[i] += t;
        t = res[i] / 10;
        res[i] %= 10;
    }
    while(res.back() == 0 && res.size() > 1) res.pop_back();
    return res;
}

int main()
{
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    std::string a, b;
    std::cin >> a >> b;
    std::vector<int> A, B, C;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    C = mul(A, B);
    for(int i = C.size() - 1; i >= 0; i--) std::cout << C[i];
    std::cout << std::endl;

    return 0;
}
