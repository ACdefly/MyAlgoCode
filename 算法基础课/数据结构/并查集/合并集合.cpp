/*
* @Author: wlun
* @Date:   2023-08-11 09:05:51
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-11 09:10:56
*/

#include <iostream>

using namespace std;

int fa[100010];

int find(int x){
    if(x != fa[x]) fa[x] = find(fa[x]);
    return fa[x];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        fa[i] = i;
    }
    while(m--){
        char c;
        int a, b;
        cin >> c >> a >> b;
        if(c == 'M'){
            if(find(a) != find(b))
                fa[find(a)] = find(b);
        } else{
            cout << (find(a) == find(b) ? "Yes" : "No") << endl;
        }
    }
    return 0;
}
