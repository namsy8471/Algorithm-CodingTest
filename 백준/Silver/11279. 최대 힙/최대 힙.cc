#include <iostream>  
#include <queue>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt;

    cin >> cnt;

    priority_queue<int> pq;

    while (cnt--)
    {
        int cmd;
        cin >> cmd;

        if (cmd == 0) {
            if (pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }

        else {
            pq.push(cmd);
        }
    }

    return 0;
}