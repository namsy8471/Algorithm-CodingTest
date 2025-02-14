#include <iostream>
#include <unordered_map>

constexpr auto LIMIT = 40;

using namespace std;

void fibonacci(int n, unordered_map<int, pair<int, int>>& um) {
    
    um[0] = make_pair(1, 0);
    um[1] = make_pair(0, 1);

    for (int i = 2; i <= n; i++) {
        um[i] = make_pair(um[i - 1].first + um[i - 2].first,
            um[i - 1].second + um[i - 2].second);
    }
}

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    unordered_map<int, pair<int, int>> um;

    fibonacci(LIMIT, um);

    for (int i = 0; i < n; i++)
    {
        int n;
        cin >> n;
        cout << um[n].first << ' ' << um[n].second << '\n';
    }

    return 0;
}
