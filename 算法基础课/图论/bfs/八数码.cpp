/*
* @Author: wlun
* @Date:   2023-08-21 15:26:26
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-21 16:08:23
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_map<string, int> mp;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

string nd = "12345678x";

bool check(int x, int y)
{
    return x >= 0 && x < 3 && y >= 0 && y < 3;
}

int bfs(string start)
{
    mp[start] = 0;
    queue<string> q;
    q.push(start);
    while(!q.empty())
    {
        auto t = q.front();
        q.pop();
        if(t == nd){
            return mp[t];
        }
        int idx = t.find('x');
        int x = idx / 3, y = idx % 3;
        string s = t;
        for(int i = 0; i < 4; i++)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if(!check(xx, yy)) continue;
            swap(s[idx], s[xx * 3 + yy]);
            if(!mp.count(s)){
                mp[s] = mp[t] + 1;
                q.push(s);
            }
            swap(s[idx], s[xx * 3 + yy]);
        }
    }
    return -1;
}

int main()
{
    string s, t;
    getline(cin, s);
    for(auto &x: s) {
        if(x != ' ') t += x;
    }
    cout << bfs(t) << endl;
    return 0;
}
