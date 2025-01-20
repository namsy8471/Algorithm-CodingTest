#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int cnt;

    cin >> cnt;

    vector<pair<int,pair<int, string>>> v;

    int queue = 0;
    while (cnt > 0)
    {
        pair<int, pair<int, string>> p;

        cin >> p.first >> p.second.second;
        p.second.first = queue++;

        v.push_back(p);

        cnt--;
    }

    sort(v.begin(), v.end());

    for (auto& i : v)
        cout << i.first << ' ' << i.second.second << '\n';

    return 0;
}