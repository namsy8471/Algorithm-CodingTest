#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        string str;

        if (cin >> str)
        {
            if (str == "push")
            {
                int num;
                cin >> num;
                q.push(num);
            }

            else if (str == "pop")
            {
                if (!q.empty()) { 
                    cout << q.front() << endl;
                    q.pop();
                }
                else cout << -1 << '\n';
            }

            else if (str == "size")
            {
                cout << q.size() << '\n';
            }

            else if (str == "empty")
            {
                cout << (q.empty() ? 1 : 0) << '\n';
            }

            else if (str == "front")
            {
                if (!q.empty()) cout << q.front() << '\n';
                else cout << -1 << '\n';
            }

            else if (str == "back")
            {
                if (!q.empty()) cout << q.back() << '\n';
                else cout << -1 << '\n';
            }
        }
    }

    return 0;
}
