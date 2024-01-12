/*
* @Author: wlun
* @Date:   2024-01-09 23:06:03
* @Last Modified by:   wlun
* @Last Modified time: 2024-01-09 23:43:42
*/

#include <iostream>
using namespace std;

const int mod = 1e9 + 7;
const int N = 55;
int f[N][3];

int main()
{
    string s = " ", t;
    cin >> t;
    s += t;
    int m = 0;
    for(int i = 1; i < s.size(); i++) {
        m = (s[i] - '0') % 3;
        f[i][m] = 1;
   /*   f[i][j] = f[i - 1][j]
        f[i][j] += f[i - 1][j - m]
        DP的状态转移：第 i 个数分为两种情况：
        (1)第 i 个数不加入子序列：那么本位就继承上一位的数据，即dp[ i ][?]+=dp[ i-1 ][?];
        (2)第 i 个数加入子序列：处理到dp[ i ][ j ]时，
            因为本位对3取余已有m，
            所以对于余数为 j 时，只需继承前数余数的j-m就行，
            但是考虑到j-m可能小于0，所以j-m替换为(j-m+3)%3
   */
        for(int j = 0; j < 3; j++) {
            f[i][j] += (f[i - 1][j] + f[i - 1][(j + 3 - m) % 3]) % mod;
        }
    }
    cout << f[s.size() - 1][0] % mod << endl;
    return 0;
}
