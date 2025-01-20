#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    vector<int> v;

    int cnt;

    cin >> cnt;

    while (cnt > 0)
    {
        int num;

        cin >> num;

        v.push_back(num);

        cnt--;
    }

    sort(v.begin(), v.end());

    for (auto i : v)
        cout << i << '\n';

    return 0;
}