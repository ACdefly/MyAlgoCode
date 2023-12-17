/*
* @Author: wlun
* @Date:   2023-08-23 00:09:13
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-23 00:23:44
*/

#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int e[N], ne[N], h[N], idx = 0;
int n1, n2, m;
bool st[N];
int match[N];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u)
{
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            st[j] = true;
            if(!match[j] || dfs(match[j])) {
                match[j] = u;
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    memset(h, -1, sizeof h);
    cin >> n1 >> n2 >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    int ans = 0;
    for(int i = 1; i <= n1; i++){
        memset(st, false, sizeof st);
        if(dfs(i)) ans++;
    }
    cout << ans << endl;
    return 0;
}
