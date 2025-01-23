#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

int main() {

    int n;

    cin >> n;

    set<string> s;

    for (int i = 0; i < n; i++)
    {
        string s1, s2;

        cin >> s1 >> s2;

        if (s.find(s1) != s.end() && s2 == "leave") s.erase(s1);
        else s.insert(s1);
    }

    vector<string> v(s.rbegin(), s.rend());

    for (const auto& s : v) cout << s << '\n';
    

    return 0;
}