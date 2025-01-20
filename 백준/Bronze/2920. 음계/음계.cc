#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> v;

    for (int i = 0; i < 8; i++)
    {
        int idx;
        cin >> idx;

        v.push_back(idx);
    }

    vector<int> asc;
    vector<int> des;

    for (int i = 1; i <= 8; i++) asc.push_back(i);
    for (int i = 8; i >= 1; i--) des.push_back(i);

    if (v == asc) cout << "ascending";
    else if (v == des) cout << "descending";
    else cout << "mixed";

    return 0;
}