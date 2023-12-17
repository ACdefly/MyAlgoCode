// Problem: P1440 求m区间内的最小值
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1440
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include <iostream>
using namespace std;

const int N = 2e6 + 5;

int a[N], q[N];

int hh = 0, tt = -1;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d\n", 0);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i < n; i++) {
		if(hh <= tt && i - m + 1 > q[hh]) hh++;
		while(hh <= tt && a[i] <= a[q[tt]]) tt--;
		q[++tt] = i;
		printf("%d\n", a[q[hh]]);
	}
	return 0;
}