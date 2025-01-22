#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

    int cnt;
    cin >> cnt;

    stack<int> stack;
    vector<int> v;

    for (int i = 0; i < cnt; i++)
    {
        int n;
        cin >> n;

        v.push_back(n);
    }

    int idx = 0;
    vector<char> ret;
    
    for (int i = 1; i <= cnt; i++)
    {
        stack.push(i);
        ret.push_back('+');

        while (!stack.empty() && stack.top() == v[idx])
        {
            stack.pop();
            ret.push_back('-');
            idx++;
        }
    }

    if (stack.empty())
    {
        for (auto c : ret)
            cout << c << '\n';
    }

    else cout << "NO";
    
    return 0;
}