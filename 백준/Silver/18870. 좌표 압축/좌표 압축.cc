#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int cnt;

    cin >> cnt;
    vector<int> v(cnt);

    for (int i = 0; i < cnt; i++) {
        cin >> v[i];
    }

    vector<int> copyV(v.begin(), v.end());
    sort(copyV.begin(), copyV.end());
    copyV.erase(unique(copyV.begin(), copyV.end()), copyV.end());

    unordered_map<int, int> m;

    for (int i = 0; i < copyV.size(); i++)
        m[copyV[i]] = i;

    for (auto& i : v) i = m[i];

    for (const auto& i : v)
        cout << i << ' ';


    return 0;
}