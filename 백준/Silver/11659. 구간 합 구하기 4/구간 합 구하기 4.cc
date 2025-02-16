#include <iostream>
#include <vector>

using namespace std;

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<long long> v(n);

    cin >> v[0];

    for (int i = 1; i < n; i++)
    {
        cin >> v[i];
        v[i] += v[i - 1];
    }

    while (m--)
    {
        int start, dest;

        cin >> start >> dest;

        int ret;
        if (start == 1) ret = v[dest - 1];
        else ret = v[dest - 1] - v[start - 2];

        cout << ret << '\n';
    }

    return 0;
}


