/*
* @Author: wlun
* @Date:   2023-08-25 15:56:16
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-25 16:17:18
*/
#include <cstring>
#include <iostream>

using namespace std;

const int N = 510;
int g[N][N];
int dp[N][N];
int main(int argc, char const *argv[])
{
    memset(dp, -0x3f, sizeof dp);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) cin >> g[i][j];
    }

    dp[0][0] = dp[0][1] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i - 1][j - 1] + g[i][j], dp[i - 1][j] + g[i][j]);
        }
    int ans = -0x3f3f3f3f;
    for(int i = 1; i <= n; i++) ans = max(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}
