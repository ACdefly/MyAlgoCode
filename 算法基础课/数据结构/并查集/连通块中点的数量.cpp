/*
* @Author: wlun
* @Date:   2023-08-11 09:12:07
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-11 09:28:23
*/

#include <iostream>

const int N = 100010;

int fa[N], idx[N];

int find(int x){
    if(x != fa[x]) fa[x] = find(fa[x]);
    return fa[x];
}

int main(int argc, char const *argv[])
{
    int n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++){
        fa[i] = i;
        idx[i] = 1;
    }
    while(m--){
        std::string s;
        std::cin >> s;
        int a, b;
        if(s == "C"){
            std::cin >> a >> b;
            if(find(a) != find(b)){
                int x = find(a), y = find(b);
                fa[x] = y;
                idx[y] += idx[x];
            }
        }else if(s == "Q1"){
            std::cin >> a>> b;
            std::cout << (find(a) != find(b) ? "No" : "Yes") << std::endl;
        }else{
            std::cin >> a;
            std::cout << idx[find(a)] << std::endl;
        }
    }
    return 0;
}
