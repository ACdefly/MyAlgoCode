/*
 * @Author: wlun
 * @Date:   2023-08-10 18:25:26
 * @Last Modified by:   wlun
 * @Last Modified time: 2023-08-10 18:25:39
 */
#include <iostream>

using namespace std;

const int N = 100010;
int stk[N], top = -1;

void push(int x) { stk[++top] = x; }
void pop() { top--; }
bool empty() { return top == -1; }
int query() { return stk[top]; }

int main() {

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
