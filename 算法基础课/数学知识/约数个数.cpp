/*
* @Author: wlun
* @Date:   2023-08-23 21:26:15
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-23 21:44:04
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
    for(auto &[_, v]: mp) ans = ans * (v + 1) % mod;
    cout << ans << endl;
    return 0;
}
