#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

void BFS(unordered_map<long long, int>& um, int s, int d)
{
    um[s] = 1;

    queue<long long> q;
    q.push(s);

    while (!q.empty())
    {
        long long pos = q.front();
        q.pop();

        if (pos * 2 <= d) {
            um[pos * 2] = um[pos * 2] == 0 ?
                um[pos] + 1 : min(um[pos * 2], um[pos] + 1);
            q.push(pos * 2);
        }
        if (pos * 10 + 1 <= d) {
            um[pos * 10 + 1] = um[pos * 10 + 1] == 0 ?
                um[pos] + 1 : min(um[pos * 10 + 1], um[pos] + 1);
            q.push(pos * 10 + 1);
        }
    }

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
   
    int s, d;

    cin >> s >> d;

    unordered_map<long long, int> um;
    
    BFS(um, s, d);

    cout << (um[d] == 0 ? -1 : um[d]);

    return 0;  
}