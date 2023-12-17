/*
* @Author: wlun
* @Date:   2023-08-24 13:49:45
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-24 14:34:17
*/

#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int prime[N], cnt = 0;
int phi[N];
bool st[N];

void solve(int n)
{
    phi[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        if(!st[i])
        {
            prime[cnt++] = i;
            phi[i] = i - 1;
        }

        for(int j = 0; prime[j] <= n / i; j++)
        {
            int t = prime[j] * i;
            st[t] = true;

            if(i % prime[j] == 0) {
                phi[t] = prime[j] * phi[i];
                break;
            }
            phi[t] = (prime[j] - 1) * phi[i];
        }
    }
}

int main()
{
    int n;
    cin >> n;
    solve(n);
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += phi[i];
    }
    cout << ans << endl;
    return 0;
}
