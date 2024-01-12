/*
* @Author: wlun
* @Date:   2024-01-09 14:45:34
* @Last Modified by:   wlun
* @Last Modified time: 2024-01-09 15:22:28
*/

#include <iostream>

using namespace std;

const int N = 3010;

int a[N], b[N], f[N][N];
int n;
// 朴素版
/*
 * 首先依据公共子序列中是否包含a[i]，将f[i][j]所代表的集合划分成两个不重不漏的子集：
 * 不包含a[i]的子集，最大值是f[i - 1][j]；
 * 包含a[i]的子集，将这个子集继续划分，依据是子序列的倒数第二个元素在b[]中是哪个数：
 * 子序列只包含b[j]一个数，长度是1；
 * 子序列的倒数第二个数是b[1]的集合，最大长度是f[i - 1][1] + 1；
 * …
 * 子序列的倒数第二个数是b[j - 1]的集合，最大长度是f[i - 1][j - 1] + 1；
*/
void solve1()
{
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= n; j ++ )
        {
            f[i][j] = f[i - 1][j];
            if (a[i] == b[j])
            {
                int maxv = 1;
                for (int k = 1; k < j; k ++ )
                    if (a[i] > b[k])
                        maxv = max(maxv, f[i - 1][k] + 1);
                f[i][j] = max(f[i][j], maxv);
            }
        }
    }

    int res = 0;
    for(int i = 1; i <= n; i++) res = max(f[n][i], res);
    cout << res << endl;
}

void solve2()
{
    for (int i = 1; i <= n; i ++ )
    {
        int maxv = 1;
        // 每次循环求得的maxv是满足a[i] > b[k]的f[i - 1][k] + 1的前缀最大值。
        // 因此可以直接将maxv提到第一层循环外面，减少重复计算，此时只剩下两重循环。
        for (int j = 1; j <= n; j ++ )
        {
            f[i][j] = f[i - 1][j];
            if (a[i] == b[j]) f[i][j] = max(f[i][j], maxv);
            if (a[i] > b[j]) maxv = max(maxv, f[i - 1][j] + 1);
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++) res = max(f[n][i], res);
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    // solve1();
    solve2();
    return 0;
}
