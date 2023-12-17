/*
* @Author: wlun
* @Date:   2023-08-15 08:24:56
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-15 09:31:00
*/

#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

unordered_map<char, int> mp;
stack<int> nums;
stack<char> op;

void init() {
    mp.insert({'+', 1});
    mp.insert({'-', 1});
    mp.insert({'*', 2});
    mp.insert({'/', 2});
}

int sum(string s){
    int res  = 0;
    for(int i = 0; i < s.size(); i++){
        res += s[i] - '0';
        if(i != s.size() - 1) res *= 10;
    }
    return res;
}

void eval(){
    int a = nums.top();
    nums.pop();
    int b = nums.top();
    nums.pop();
    char c = op.top();
    op.pop();
    if(c == '+') nums.push(a + b);
    else if(c == '-') nums.push((b - a));
    else if(c == '*') nums.push((b * a));
    else if(c == '/') nums.push((b / a));
}

int main()
{
    string s;
    cin >> s;
    init();
    for(int i = 0; i < s.size();i++){
        string t;
        if(s[i] >= '0' && s[i] <= '9'){
            while( i < s.size() && s[i] >= '0' && s[i] <= '9') t += s[i], i++;
            i--;
            nums.push(sum(t));
        }
        else if(s[i] == '(') op.push(s[i]);
        else if(s[i] == ')'){
            while(op.top() != '(') eval();
            op.pop();
        } else {
            while(op.size() && mp[op.top()] >= mp[s[i]]) eval();
            op.push(s[i]);
        }
    }
    while(op.size()) eval();
    cout << nums.top() << endl;
    return 0;
}
