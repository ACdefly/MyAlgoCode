/*
* @Author: wlun
* @Date:   2023-08-08 23:37:53
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-08 23:46:26
*/


#include <iostream>
#include <cstring>

const int N = 1e5 + 3;

int e[N], ne[N], h[N], idx = 0;

void insert(int x){
    int k = ((x % N) + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool find(int x){
    int k = ((x % N) + N) % N;
    for(int i = h[k]; ~i; i = ne[i]){
        if(e[i] == x) return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    memset(h, -1, sizeof(h));
    int n;
    std::cin >> n;
    while(n--){
        char c;
        int x;
        std::cin >> c >> x;
        if(c == 'I') insert(x);
        else {
            std::cout << (find(x) ? "Yes" : "No") << "\n";
        }
    }
    return 0;
}
