/*
* @Author: wlun
* @Date:   2023-08-20 23:12:42
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-20 23:12:50
*/
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N];
int n, k;
int cnt = 0;

void up(int u) // 上浮
{
    if(u / 2 && a[u] < a[u / 2])
    {
        swap(a[u], a[u / 2]);
        up(u / 2);
    }
}

void down(int u) // 下沉
{
    int v = u;
    if(u * 2 <= cnt && a[u * 2] < a[v]) v = u * 2;
    if(u * 2 + 1 <= cnt && a[u * 2 + 1] < a[v]) v = u * 2 + 1;
    if(u != v){
        swap(a[v], a[u]);
        down(v);
    }
}

void push(int x) // 压入top
{
    a[++cnt] = x;
    up(cnt);
}

void pop() // 弹出top
{
    a[1] = a[cnt--];
    down(1);
}

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cnt = n;
    for(int i = n / 2; i >= 1; i--)
    {
        down(i);
    }
    while(k--)
    {
        cout << a[1] << ' ';
        pop();
    }
    return 0;
}
