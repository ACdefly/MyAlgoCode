/*
* @Author: wlun
* @Date:   2023-08-21 16:25:34
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-21 20:31:38
*/
#include <iostream>
#include <cstring>

using namespace std;
const int N = 100010;

int h[N], e[N << 1], ne[N << 1], idx = 0;
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int ans = N;
int n;

int dfs(int u)
{
    st[u] = true;
    int sum = 1, res = 0;
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            int s = dfs(j);
            res = max(res, s); // res 为最大子树
            sum += s; // sum 为以u 为顶点的 子树之和 + 1(即u)
        }
    }
    cout << u << "->" << sum << endl;
    res = max(n - sum, res); // n - sum 是已经遍历过的子树 (st[u - 1] == true)
    ans = min(ans, res);
    return sum;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}
