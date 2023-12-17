/*
* @Author: wlun
* @Date:   2023-08-18 07:02:10
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-18 07:18:22
*/
#include <bits/stdc++.h>

const int N = 1e5 + 10;

int tr[N][30], cnt[N], idx = 0;
char str[N], c;

void insert(char str[])
{
    int p = 0;
    for(int i = 0; str[i]; i++){
        int u = str[i] - 'a';
        if(!tr[p][u]) tr[p][u] = ++idx;
        p = tr[p][u];
    }
    cnt[p]++;
}

int find(char str[])
{
    int p = 0;
    for(int i = 0; str[i]; i++){
        int u = str[i] - 'a';
        if(!tr[p][u]) return 0;
        p = tr[p][u];
    }
    return cnt[p];
}

void solve() {
    std::cin >> c >> str;
    // std::cout << c << ' ' << str << "\n";
    if(c == 'I') insert(str);
    else std::cout << find(str) << "\n";
}

int main()
{
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int t;
    std::cin >> t;
    while(t--) solve();

    return 0;
}
