#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int a[N], q[N];
int hh = 0, tt = -1;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++)
    {
        if(hh <= tt && i - k + 1 > q[hh]) hh++;
        while(hh <= tt && a[i] <= a[q[tt]]) tt--;
        q[++tt] = i;
        if(i - k + 1 >= 0) cout << a[q[hh]] << ' ';
    } cout << endl;
    hh = 0, tt = -1;
    for(int i = 0; i < n; i++)
    {
        if(hh <= tt && i - k + 1 > q[hh]) hh++;
        while(hh <= tt && a[i] >= a[q[tt]]) tt--;
        q[++tt] = i;
        if(i - k + 1 >= 0) cout << a[q[hh]] << ' ';
    } cout << endl;
    return 0;
}
