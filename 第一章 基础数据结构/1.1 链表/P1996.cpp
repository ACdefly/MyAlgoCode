// Problem: P1996 约瑟夫问题
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1996
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>

using namespace std;

typedef struct ListNode
{
  int val;
  ListNode* next;
  ListNode(): val(0), next(nullptr){}
  ListNode(int v): val(v), next(nullptr){}
}ListNode;

int main()
{
  int n, m;
  cin >> n >> m;
  ListNode h;
  ListNode *p = &h;
  ListNode *q = &h;
  for(int i = 1; i <= n; i++) {
    ListNode *node = new ListNode(i);
    p->next = node;
    p = p->next;
  }
  p->next = h.next;

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j < m; j++) {
      q = q->next;
    }
    cout << q->next->val << ' ';
    ListNode *node = q->next;
    q->next = q->next->next;
    delete node;
  }
  return 0;
}
