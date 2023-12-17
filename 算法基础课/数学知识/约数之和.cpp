/*
* @Author: wlun
* @Date:   2023-08-23 22:08:52
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-23 22:18:59
*/

#include <iostream>
#include <unordered_map>

using namespace std;

const int mod = 1e9 + 7;

int main()
{
    unordered_map<int, int> mp;
    int n;
    cin >> n;
    while(n--)
    {
        int x; cin >> x;
        for(int i = 2; i <= x / i; i++) {
            while(x % i == 0) mp[i]++, x /= i;
        }
        if(x > 1) mp[x]++;
    }
    long long ans = 1;
    for(auto &[k, v]: mp) {
        long long sum = 1;
        for(int i = 1; i <= v; i++) {
            sum = (sum * k + 1) % mod;
        }
        ans = ans * sum % mod;
    }
    cout << ans << endl;
    return 0;
}
