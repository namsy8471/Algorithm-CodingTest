#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int cnt;
        cin >> cnt;

        unordered_map<string, int> m;

        for (int j = 0; j < cnt; j++)
        {
            string name, part;
            cin >> name >> part;

            m[part]++;
        }

        int ret = 1;
        
        for (auto pair : m)
            ret *= (pair.second + 1);

        ret--;

        cout << ret << '\n';
    }

    return 0;
}


