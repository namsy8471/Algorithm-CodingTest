#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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