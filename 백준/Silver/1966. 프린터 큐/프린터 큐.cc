#include <iostream>
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

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for (int i = 0; i < cnt; i++)
        {
            int num;
            cin >> num;

            q.push({ num, i });
            pq.push(num);
        }

        int order = 0;

        while (!q.empty())
        {
            auto [priority, idx] = q.front();
            q.pop();

            if (priority == pq.top())
            {
                order++;
                pq.pop();

                if (idx == pos) { 
                    cout << order << '\n';
                    break; 
                }
            }

            else{
                q.push({priority, idx});
            }
        }
    }

    return 0;
}


