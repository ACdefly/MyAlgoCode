/*
* @Author: wlun
* @Date:   2023-08-20 23:14:12
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-20 23:33:07
*/

#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int h[N], ph[N], hp[N];
int sz = 0, cnt = 0;

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void up(int u)
{
    if(u / 2 && h[u / 2] > h[u])
    {
        heap_swap(u / 2, u);
        up(u / 2);
    }
}

void down(int u)
{
    int v = u;
    if(u * 2 <= sz && h[u * 2] < h[v]) v = 2 * u;
    if(u * 2 + 1 <= sz && h[u * 2 + 1] < h[v]) v = 2 * u + 1;
    if(u != v)
    {
        heap_swap(u, v);
        down(v);
    }
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        if(s == "I"){
            int x; cin >> x;
            sz++, cnt++;
            ph[cnt] = sz, hp[sz] = cnt;
            h[sz] = x;
            up(sz);
        }
        else if(s == "PM") cout << h[1] << endl;
        else if(s == "DM") {
            heap_swap(1, sz);
            sz--;
            down(1);
        }
        else if(s == "D")
        {
            int k; cin >> k;
            k = ph[k];
            heap_swap(k, sz);
            sz--;
            up(k), down(k);
        }
        else {
            int k, x;
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            up(k), down(k);
        }
    }
    return 0;
}
