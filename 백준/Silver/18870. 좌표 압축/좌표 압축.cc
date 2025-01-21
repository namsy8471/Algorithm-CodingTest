#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int cnt;

    cin >> cnt;
    vector<int> v;

    while (cnt > 0)
    {
        int i;
        cin >> i;

        v.push_back(i);

        cnt--;
    }

    vector<int> copyV(v.begin(), v.end());
    sort(copyV.begin(), copyV.end());

    map<int, int> m;

    cnt = 0;

    for (int i = 0; i < copyV.size(); i++)
        if(m.find(copyV[i]) == m.end()) m[copyV[i]] = cnt++;

    for (int i = 0; i < v.size(); i++)
        v[i] = m[v[i]];

    for (auto& i : v)
        cout << i << ' ';


    return 0;
}