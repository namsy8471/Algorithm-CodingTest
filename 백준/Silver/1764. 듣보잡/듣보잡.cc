#include <iostream>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    unordered_set<string> s1;
    unordered_set<string> s2;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        s1.insert(s);
    }

    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        s2.insert(s);
    }

    int ret = 0;
    set<string> retS;

    for (const auto& i : s1)
    {
        if (s2.find(i) != s2.end()) 
        {
            retS.insert(i);
            ret++;
        }
    }

    cout << ret << '\n';
    for (const auto& s : retS) cout << s << '\n';


    return 0;
}