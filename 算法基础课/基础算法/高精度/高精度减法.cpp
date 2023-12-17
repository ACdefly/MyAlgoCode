/*
* @Author: wlun
* @Date:   2023-07-27 22:05:01
* @Last Modified by:   wlun
* @Last Modified time: 2023-07-27 22:43:52
*/

#include <bits/stdc++.h>
#include <functional>
#include <vector>

using i64 = long long;
using namespace std;

bool cmp(vector<int>& A, vector<int>& B){
    if(A.size() != B.size()) return A.size() > B.size();
    else{
        for(int i = A.size() - 1; i >= 0; i--){
            if(A[i] != B[i]) return A[i] > B[i];
        }
    }
    return true;
}

vector<int> sub(vector<int>& A, vector<int>& B){
    int t = 0;
    vector<int> res;
    for(int i = 0; i < A.size(); i++){
        t += A[i];
        if(i < B.size()) t -= B[i];
        res.push_back((t + 10) % 10);
        t = t < 0 ? -1 : 0;
    }
    while(res.back() == 0 && res.size() > 1) res.pop_back();
    return res;
}

void solve() {
    string a, b;
    cin >> a >> b;
    vector<int> A{}, B{};
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    if(cmp(A, B)){
        auto res = sub(A, B);
        for(int i = res.size() - 1; i >= 0; i--) cout << res[i];
        cout << endl;
    }else{
        cout << "-";
        auto res = sub(B, A);
        for(int i = res.size() - 1; i >= 0; i--) cout << res[i];
        cout << endl;
    }
}

int main()
{
    std::cin.tie(nullptr) -> sync_with_stdio(false);

    solve();

    return 0;
}
