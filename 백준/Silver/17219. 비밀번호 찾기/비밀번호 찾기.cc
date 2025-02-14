#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    unordered_map<string, string> um;

    for (int i = 0; i < n; i++)
    {
        string url, password;
        cin >> url >> password;
        um[url] = password;
    }

    for (int i = 0; i < m; i++)
    {
        string url;
        cin >> url;
        cout << um[url] << '\n';
    }

    return 0;
}
