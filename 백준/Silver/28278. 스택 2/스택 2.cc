#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;

    cin >> n;

    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        int cmd;

        if (cin >> cmd) {
            switch (cmd)
            {
            case 1:
                int num;
                cin >> num;
                s.push(num);
                break;
            case 2:
                cout << (s.empty() ? -1 : s.top()) << '\n';
                if (!s.empty()) s.pop();
                break;
            case 3:
                cout << s.size() << '\n';
                break;
            case 4:
                cout << s.empty() << '\n';
                break;
            case 5:
                cout << (s.empty() ? -1 : s.top()) << '\n';
                break;
            default:
                break;
            }
        }
    }
    
    return 0;
}