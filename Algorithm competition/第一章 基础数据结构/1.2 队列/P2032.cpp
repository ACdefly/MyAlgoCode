// Problem: P2032 扫描
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2032
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) {
		if(hh <= tt && i - k + 1 > q[hh]) hh++;
		while(hh <= tt && a[i] >= a[q[tt]]) tt--;
		q[++tt] = i;
		if(i - k + 1 >= 0) cout << a[q[hh]] << endl;
	}
	return 0;
}