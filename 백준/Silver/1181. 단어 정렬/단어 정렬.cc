#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool CustomSort(const string& a, const string& b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    
    return a < b;
}

int main() {

    int cnt;

    cin >> cnt;

    vector<string> v;

    while (cnt > 0)
    {
        string s;

        cin >> s;

        v.push_back(s);

        cnt--;
    }

    sort(v.begin(), v.end(), CustomSort);
    auto last = unique(v.begin(), v.end());
    v.erase(last, v.end());

    for (auto& i : v)
        cout << i << endl;

    return 0;
}