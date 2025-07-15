#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define MAX_POS 100001

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;

    cin >> N >> K;

    if (N >= K)
    {
        cout << N - K;
        return 0;
    }

    vector<int> time(MAX_POS, std::numeric_limits<int>::max());

    time[N] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, N });

    while (!pq.empty())
    {
        auto info = pq.top();
        pq.pop();

        int current_time = info.first;
        int current_pos = info.second;

        if (time[current_pos] < current_time)
            continue;

        if (current_pos == K) break;

        int multi = 2 * current_pos;
        if (multi < MAX_POS && time[multi] > time[current_pos])
        {
            time[multi] = time[current_pos];
            pq.push({ time[multi], multi });
        }


        int left = current_pos - 1;       
        if (left >= 0 && time[left] > time[current_pos] + 1)
        {
            time[left] = time[current_pos] + 1;
            pq.push({ time[left], left });
        }
        

        int right = current_pos + 1; 
        if (right < MAX_POS && time[right] > time[current_pos] + 1)
        {
            time[right] = time[current_pos] + 1;
            pq.push({ time[right], right });
        }
        
    }

    cout << time[K];

    return 0;  
}