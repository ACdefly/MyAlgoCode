/*
* @Author: wlun
* @Date:   2023-08-02 21:27:00
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-02 21:35:51
*/
#include <bits/stdc++.h>

using i64 = long long;

const int N = 1010;
int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c){
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            std::cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            insert(i, j, i, j, a[i][j]);
        }
    }
    while(q--){
        int x1, y1, x2, y2, c;
        std::cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            std::cout << b[i][j] << ' ';
        }std::cout << std::endl;
    }
}

int main()
{
    std::cin.tie(nullptr) -> sync_with_stdio(false);

    solve();

    return 0;
}
