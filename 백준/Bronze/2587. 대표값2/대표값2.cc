#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    vector<int> v;

    for (int i = 0; i < 5; i++)
    {
        int num;
        
        cin >> num;

        v.push_back(num);
    }

    sort(v.begin(), v.end());

    int avg = 0;

    for (auto i : v)
        avg += i;

    cout << avg / 5 << endl;
    cout << v[v.size() / 2] << endl;

    return 0;
}