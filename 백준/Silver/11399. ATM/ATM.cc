#include <iostream>
#include <set>

using namespace std;

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    multiset<int> ms;

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        ms.insert(p);
    }

    int ret = 0;

    for (int i = 0; i < n; i++) {
        for (auto it = next(ms.rbegin(), i); it != ms.rend(); it++)
        {
            ret += *it;
        }
    }

    cout << ret;

    return 0;
}
