/*
* @Author: wlun
* @Date:   2024-01-09 20:40:45
* @Last Modified by:   wlun
* @Last Modified time: 2024-01-09 22:28:57
*/

#include <iostream>
#include <vector>
#define mod 10007
using namespace std;

const int N = 1e5 + 10;

struct Node {
    int idx;
    int num;
    int color;
}node[N];

vector<Node> vec[N][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> node[i].num, node[i].idx = i;
    for(int i = 1; i <= n; i++) cin >> node[i].color;
    for(int i = 1; i <= n; i++) {
        int c = node[i].color;
        // 颜色相同, 奇偶性相同的归为一类
        vec[c][i & 1].push_back(node[i]);
    }
    long long res = 0;
    for(int c = 1; c <= m; c++)
        for(int i = 0; i < 2; i++) {
            long long sum1 = 0, sum2 = 0, sum3 = 0;
            if(vec[c][i].size() <= 1) continue;
            for(auto &item: vec[c][i])
            {
                sum1 += item.idx;
                sum2 += item.num;
                sum3 = (sum3 + 1LL * item.idx * item.num) % mod;
            }
            res = (res + ((sum1 % mod) * (sum2 % mod)) + ((vec[c][i].size() - 2) * sum3)) % mod;
        }
    cout << res << endl;
    return 0;
}
