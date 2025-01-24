#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    unordered_set<int> s1;
    unordered_set<int> s2;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        s1.insert(num);
    }

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        s2.insert(num);
    }

    unordered_set<int> retS;

    for (const auto& i : s1)
        if (s2.find(i) == s2.end()) retS.insert(i);

    for (const auto& i : s2)
        if (s1.find(i) == s1.end()) retS.insert(i);

    cout << retS.size() << endl;

    return 0;
}