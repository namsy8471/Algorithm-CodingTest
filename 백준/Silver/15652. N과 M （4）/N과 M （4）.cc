#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> result;

void backtrack(int start)
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

    for (int i = start; i <= N; i++)
    {
        result.push_back(i);
        backtrack(i);
        result.pop_back();
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
   
    cin >> N >> M;

    backtrack(1);

    return 0;  
}