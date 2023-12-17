/*
* @Author: wlun
* @Date:   2023-08-23 10:54:55
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-23 11:00:46
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> vec;
    for(int i = 1; i <= n / i; i++){
        if(n % i == 0) {
            vec.push_back(i);
            if(n / i != i) vec.push_back(n / i);
        }
    }
    sort(vec.begin(), vec.end());
    for(auto x: vec) cout << x << ' ';
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    while(n--) solve();
    return 0;
}
