#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using Edge = pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;

    cin >> N >> K;

    vector<pair<int,int>> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;

    vector<int> memo(K + 1, 0);

    for (int i = 0; i < N; i++)
    {
        int weight = v[i].first;
        int value = v[i].second;

        for (int w = K; w >= weight; w--)
        {
            memo[w] = max(memo[w], memo[w - weight] + value);
        }
    }

    cout << memo[K];

    return 0;  
}