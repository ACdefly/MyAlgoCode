/*
* @Author: wlun
* @Date:   2023-08-21 15:14:42
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-21 15:24:51
*/

#include <iostream>
#include <queue>
#include <cstring>
#define x first
#define y second

using namespace std;
using PII = pair<int, int>;

const int N = 110;
int g[N][N];
bool st[N][N];
int dist[N][N];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;

bool check(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < m && !st[x][y] && g[x][y] != 1;
}

int bfs()
{

    queue<PII> q;
    q.push({0, 0});
    st[0][0] = true;
    dist[0][0] = 0;
    while(!q.empty())
    {
        auto t = q.front();
        q.pop();
        for(int i = 0; i <4; i++){
            int xx = dx[i] + t.x;
            int yy = dy[i] + t.y;
            if(check(xx, yy)){
                q.push({xx, yy});
                st[xx][yy] = true;
                dist[xx][yy] = dist[t.x][t.y] + 1;
            }
        }
    }
    return dist[n - 1][m - 1];
}

int main()
{

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j ++)
        {
            cin >> g[i][j];
        }
    }
    cout << bfs() << endl;
    return 0;
}
