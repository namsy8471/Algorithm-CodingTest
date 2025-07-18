#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void Calculate(const vector<pair<int, int>>& chickens,
    const vector<pair<int, int>>& houses,
    vector<int>& chickenIndice, int& nowMin)
{
    int all_dist = 0;

    for (const auto& house : houses)
    {
        int house_dist = std::numeric_limits<int>::max();
        
        for (const auto& idx : chickenIndice)
        {
            const auto chicken = chickens[idx];
            auto dist = abs(house.first - chicken.first) + abs(house.second - chicken.second);
            house_dist = min(dist, house_dist);
        }

        all_dist += house_dist;
    }

    nowMin = min(nowMin, all_dist);
}

void Backtracking(const vector<pair<int,int>>& chicken,
    const vector<pair<int, int>>& house, vector<int>& chickenIndice,
    const int maxDepth, int currentDepth, int startIdx, int& nowMin)
{
    if (currentDepth == maxDepth)
    {
        Calculate(chicken, house, chickenIndice, nowMin);
        return;
    }

    for (int i = startIdx; i < chicken.size(); i++)
    {
        chickenIndice.push_back(i);
        Backtracking(chicken, house, chickenIndice, maxDepth, currentDepth + 1, i + 1, nowMin);
        chickenIndice.pop_back();
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;

    cin >> N >> M;

    vector<pair<int, int>> chicken;
    vector<pair<int, int>> house;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int info;
            cin >> info;

            if (info == 1)
                house.push_back({ i, j });
            else if (info == 2)
                chicken.push_back({ i, j });
        }
    }

    int ret = std::numeric_limits<int>::max();
    vector<int> chickenIndice;
    Backtracking(chicken, house, chickenIndice, M, 0, 0, ret);

    cout << ret;

    return 0;  
}