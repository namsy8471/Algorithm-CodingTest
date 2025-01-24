#include <iostream>
#include <unordered_set>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    unordered_set<int> s;
    int same = 0;

    for (int i = 0; i < n + m; i++)
    {
        int num;
        cin >> num;
        if (s.find(num) == s.end()) s.insert(num);
        else same++;
    }

    int ret = s.size() - same;

    cout << ret << endl;

    return 0;
}