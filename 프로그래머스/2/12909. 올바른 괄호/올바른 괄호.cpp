#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stk;
    
    for(auto c : s)
    {
        if(c == '(') stk.push(c);
        else
        {
            if(stk.empty()) return false;
            stk.pop();
        }
    }

    if (!stk.empty()) return false;
    
    return true;
}