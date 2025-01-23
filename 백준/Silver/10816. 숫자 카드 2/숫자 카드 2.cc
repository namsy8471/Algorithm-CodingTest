#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {

    int n, m;

    cin >> n;
    
    unordered_map<int, int> map;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        map[num]++;
    }

    cin >> m;

    vector<int> v(m);
    for (int i = 0; i < m; i++) cin >> v[i];

    for (const auto& i : v) cout << map[i] << ' ';

    return 0;
}