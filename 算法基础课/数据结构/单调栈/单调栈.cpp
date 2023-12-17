/*
* @Author: wlun
* @Date:   2023-08-10 23:52:39
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-10 23:59:53
*/

#include <iostream>

using namespace std;

const int N = 100010;
int stk[N], a[N];
int top = -1;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        if(i == 0) {
            cout << - 1 << ' ';
            stk[++top] = a[i];
        }
        else{
            if(stk[top] < a[i]) {
                cout << stk[top] << ' ';
                stk[++top] = a[i];
            }
            else{
                while(stk[top] >= a[i] && top != -1) top--;
                if(top == -1) cout << - 1 << ' ';
                else{
                    cout << stk[top] << ' ';
                }
                stk[++top] = a[i];
            }
        }
    }
    return 0;
}
