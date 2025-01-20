#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int cnt;

    cin >> cnt;

    vector<pair<int, int>> v;

    while (cnt > 0)
    {
        pair<int, int> p;

        cin >> p.second >> p.first;

        v.push_back(p);

        cnt--;
    }

    sort(v.begin(), v.end());

    for (auto i : v)
        cout << i.second << " " << i.first << '\n';

    return 0;
}