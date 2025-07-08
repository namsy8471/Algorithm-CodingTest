#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> result;
vector<bool> isVisited;

void backtrack(vector<int>& v)
{
    if (result.size() == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    int prev_num = 0;

    for (int i = 0; i < N; i++)
    {
        if (isVisited[i] || prev_num == v[i]) continue;

        isVisited[i] = true;
        result.push_back(v[i]);
        prev_num = v[i];
        
        backtrack(v);
        
        isVisited[i] = false;
        result.pop_back();
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
   
    cin >> N >> M;
    vector<int> nums;
    isVisited.resize(N, false);

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());

    backtrack(nums);

    return 0;  
}