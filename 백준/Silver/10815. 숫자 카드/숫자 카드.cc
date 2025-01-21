#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {

    int cnt;
    unordered_set<int> s;

    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        int n;
        cin >> n;
        s.insert(n);
    }

    cin >> cnt;
    vector<bool> v(cnt);

    for (int i = 0; i < cnt; i++) {
        int n;
        cin >> n;
        v[i] = s.find(n) != s.end();
    }

    for (const auto& b : v)
        cout << b << ' ';
    
    return 0;
}