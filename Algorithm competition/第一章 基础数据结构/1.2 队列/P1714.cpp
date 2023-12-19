// Problem: P1714 切蛋糕
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1714
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;

const int N = 5e5 + 5;

int s[N], q[N];
int ans = -500 * N;
int hh = 0, tt = -1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	//s[l, r] 的和为 s[r] - s[l - 1]
	// 以i为尾节点, 在队列内寻找符合条件的最小值 ans = s[i] - min(s[i - 1]...s[i - k])
	for(int i = 1; i <= n; i++) cin >> s[i], s[i] += s[i - 1];
	for(int i = 1; i <= n; i++) {
		if(hh <= tt && i - k > q[hh]) hh++;
		while(hh <= tt && s[i - 1] < s[q[tt]]) tt--;
		q[++tt] = i - 1;
		if(hh <= tt) ans = max(ans, s[i] - s[q[hh]]); 
	}
	cout << ans << endl;
	return 0;
}


