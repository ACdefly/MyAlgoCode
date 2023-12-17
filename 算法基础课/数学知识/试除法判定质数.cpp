/*
* @Author: wlun
* @Date:   2023-08-23 08:35:07
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-23 08:38:20
*/
#include <functional>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    function<bool(int)> isPrime = [&](int x) -> bool {
        if(x < 2) return false;
        for(int i = 2; i <= x / i; i++)
        {
            if(x % i == 0) return false;
        }
        return true;
    };
    while(n--) {
        int x; cin >> x;
        cout << (isPrime(x) ? "Yes" : "No") << endl;
    }
    return 0;
}
