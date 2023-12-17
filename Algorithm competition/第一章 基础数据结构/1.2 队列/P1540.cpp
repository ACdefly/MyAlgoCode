// Problem: P1540 [NOIP2010 提高组] 机器翻译
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1540
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int q[N];
int hh = 0, tt = - 1;

int main()
{
	int m, n;
	cin >> m >> n;
	int a[n + 10];
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		bool f = false;
		for(int j = hh; j <= tt; j++) {
			if(a[i] == q[j]) {
				f = true;
				break;
			}
		}
		if(!f) {
			q[++tt] = a[i];
			
			if(tt - hh + 1 > m) hh++;
		}
	}
	cout << tt + 1 << endl;
	return 0;
}