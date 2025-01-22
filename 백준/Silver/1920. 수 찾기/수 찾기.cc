#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n, m;

    cin >> n;
    unordered_set<int> s;

    for (int i = 0; i < n; i++) {
        int n;
        cin >> n;
        s.insert(n);
    }

    cin >> m;
    vector<int> v2(m);
    
    for (auto& i : v2)
        cin >> i;
   
    for (auto i : v2)
        cout << (s.find(i) != s.end()) <<'\n';

    return 0;
}