/*
* @Author: wlun
* @Date:   2023-08-10 18:30:19
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-10 21:26:55
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    string a, b;
    cin >> n >> a;
    cin >> m >> b;
    vector<int> idx;
    function<void(string, string)> kmp = [&](string a, string b){
        int m = a.size(), n = b.size();
        vector<int> Next(n, 0);
        for(int i = 1, j = 0; i < n; i++){
            while(j && b[i] != b[j]) j = Next[j - 1];
            if(b[i] == b[j]) j++;
            Next[i] = j;
        }
        for(int x: Next) cout << x << ' ';
        cout << endl;
        for(int i = 0, j = 0; i < m; i++){
            while(j && a[i] != b[j]) j = Next[j - 1];
            if(a[i] == b[j]){
                j++;
                if(j == n) idx.push_back(i - j + 1);
            }
        }
    };
    a = "abababa", b = "abacabab";
    kmp(a, b);

    return 0;
}
