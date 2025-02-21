#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    while (n--)
    {
        int cnt, pos;

        cin >> cnt >> pos;

        queue<pair<int,int>> q;
        map<int, int> m;

        for (int i = 0; i < cnt; i++)
        {
            int num;
            cin >> num;

            q.push(make_pair(num, i));
            m[num]++;
        }

        int priority = 9;
        int order = 0;

        while (!q.empty())
        {
            if (m[priority] == 0)
            {
                priority--;
                continue;
            }

            if (q.front().first == priority)
            {
                order++;
                if (q.front().second == pos) break;

                q.pop();
                m[priority]--;
            }

            else
            {
                q.push(q.front());
                q.pop();
            }
        }
        
        cout << order << '\n';
    }

    return 0;
}


