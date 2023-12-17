/*
* @Author: wlun
* @Date:   2023-08-10 18:28:18
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-10 18:28:31
*/
#include <iostream>

using namespace std;

const int N = 100010;
int q[N], hh, tt;

void init() { hh = 0, tt = -1; }

void push(int x) { q[++tt] = x; }

void pop() { hh++; }

bool empty() { return hh > tt; }

int query() { return q[hh]; }

int main() {
    init();
    int n;
    cin >> n;
    string op;
    int x;
    while (n--) {
        cin >> op;
        if (op == "push") {
            cin >> x;
            push(x);
        } else if (op == "pop") {
            pop();
        } else if (op == "empty") {
            cout << (empty() ? "YES" : "NO") << endl;
        } else {
            cout << query() << endl;
        }
    }
    return 0;
}
