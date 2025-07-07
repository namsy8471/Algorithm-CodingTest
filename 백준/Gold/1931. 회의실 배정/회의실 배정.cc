#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;

    std::cin >> N;

    std::vector<std::pair<int, int>> v;

    for (int i = 0; i < N; i++)
    {
        int s, d;

        std::cin >> s >> d;

        v.push_back({ s, d });
    }

    std::sort(v.begin(), v.end(),
        [](const std::pair<int, int> a, const std::pair<int, int> b) {
            return std::tie(a.second, a.first) < std::tie(b.second, b.first);
        }
    );

    int ret = 0;
    int endTime = 0;

    for (auto pair : v)
    {
        if (endTime <= pair.first)
        {
            endTime = pair.second;
            ret++;
        }
    }

    std::cout << ret;

    return 0;  
}