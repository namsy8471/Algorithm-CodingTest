#include <iostream>
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

    sort(v.begin(), v.end());

    for (auto i : v)
        cout << i << endl;

    return 0;
}