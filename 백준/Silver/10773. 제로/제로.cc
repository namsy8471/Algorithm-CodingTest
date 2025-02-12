#include <iostream>
#include <stack>

using namespace std;

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if (num == 0 && !s.empty()) s.pop();
        else s.push(num);
    }

    int ret = 0;

    while (!s.empty())
    {
        ret += s.top();
        s.pop();
    }

    cout << ret;

    return 0;
}
