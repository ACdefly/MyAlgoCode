/*
* @Author: wlun
* @Date:   2023-08-25 19:26:51
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-25 20:15:40
*/

#include <iostream>

using namespace std;

const int N = 1010;
char a[N], b[N];
int f[N][N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s%s", a + 1, b + 1);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if(a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 1;
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
