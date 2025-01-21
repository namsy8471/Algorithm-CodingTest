#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {

    int cnt;
    set<int> s1;

    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        int n;
        cin >> n;
        s1.insert(n);
    }

    cin >> cnt;
    vector<pair<int, bool>> v;

    for (int i = 0; i < cnt; i++) {
        int n;
        cin >> n;
        v.push_back(make_pair(n, false));
        if (s1.find(n) != s1.end()) v[i].second = true;
    }

    for (const auto& i : v)
        cout << i.second << ' ';
    
    return 0;
}