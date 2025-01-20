#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    vector<int> v;

    int cnt, cut;

    cin >> cnt >> cut;

    while (cnt > 0)
    {
        int num;

        cin >> num;

        v.push_back(num);

        cnt--;
    }

    sort(v.begin(), v.end(), greater<int>());

    cout << v[cut - 1] << endl;

    return 0;
}