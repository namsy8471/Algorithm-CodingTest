#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {

    int n, m;

    cin >> n >> m;

    unordered_set<string> set;

    for (int i = 0; i < n; i++)
    {
        string s;

        cin >> s;

        set.insert(s);
    }

    int ret = 0;

    for (int i = 0; i < m; i++)
    {
        string s;

        cin >> s;

        if (set.find(s) != set.end()) ret++;
    }

    cout << ret << endl;

    return 0;
}