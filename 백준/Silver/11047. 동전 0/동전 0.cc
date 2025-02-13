#include <iostream>
#include <stack>

using namespace std;

int calculateLeastAmount(stack<int>& s, int k)
{
    int ret = 0;

    while (!s.empty() || k != 0)
    {
        if (s.top() > k)
        {
            s.pop();
            continue;
        }

        k -= s.top();
        ret++;
    }

    return ret;
}

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        int amount;
        cin >> amount;
        s.push(amount);
    }

    cout << calculateLeastAmount(s, k);

    return 0;
}
