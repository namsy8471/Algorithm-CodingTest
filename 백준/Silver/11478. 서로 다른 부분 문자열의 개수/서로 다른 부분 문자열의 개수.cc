#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> s;

    unordered_set<string> set;

    for (int i = 0; i < s.size(); i++)
    {
        string subs = "";
        for (int j = i; j < s.size(); j++)
        {
            subs += s[j];
            set.insert(subs);
        }
    }

    cout << set.size();

    return 0;
}