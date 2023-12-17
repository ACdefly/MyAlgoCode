/*
* @Author: wlun
* @Date:   2023-08-09 16:11:08
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-09 17:04:25
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(vector<int>& A, vector<int>& B){
    if(A.size() != B.size()) return A.size() > B.size();
    for(int i = A.size() - 1; i >= 0; i--){
        if(A[i] != B[i]) return A[i] > B[i];
    }
    return true;
}

vector<int> sub(vector<int>& A, vector<int>& B){
    vector<int> res;
    int t = 0;
    for(int i = 0; i < A.size() || t; i++){
        if(i < A.size()) t += A[i];
        if(i < B.size()) t -= B[i];
        res.push_back((t + 10) % 10);
        if(t < 0) t = -1;
        else t = 0;
    }
    while(res.back() == 0 && res.size() > 1) res.pop_back();
    return res;
}

vector<int> div(vector<int>& A, vector<int>& B, vector<int>& r){
    vector<int> C;
    if(!cmp(A,B)){
        C.push_back(0);
        r=A;
        return C;
    }

    int j = B.size();
    r.assign(A.end() - j, A.end());
    while(j <= A.size()){
        int k = 0;
        while(cmp(r, B)){
            r = sub(r, B);
            k++;
        }
        C.push_back(k);
        if(j < A.size()) r.insert(r.begin(), A[A.size() - j - 1]);
        j++;
        if(r.size() > 1 && r.back() == 0) r.pop_back();
    }
    reverse(C.begin(), C.end());
    while(C.back() == 0 && C.size() > 1) C.pop_back();
    return C;
}

int main()
{
    string a, b;
    cin >> a >> b;
    vector<int> A, B, C, r;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    C = div(A, B, r);
    for(int i = C.size() - 1; i >= 0; i--) cout << C[i];
    cout <<endl;
    for(int i = r.size() - 1; i >= 0; i--) cout << r[i];
    cout <<endl;

    return 0;
}
