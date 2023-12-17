/*
* @Author: wlun
* @Date:   2023-08-02 16:26:57
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-02 16:48:04
*/

#include <bits/stdc++.h>

using i64 = long long;

const int N = 1010;

int s[N][N];
int n, m, q;

void solve() {
    memset(s, 0, sizeof s);
    std::cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            std::cin >> s[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] ;
        }
    }

    while(q--){
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 -1] << std::endl;
    }
}

int main()
{
    std::cin.tie(nullptr) -> sync_with_stdio(false);

    solve();

    return 0;
}

