#include <iostream>  
#include <vector>
#include <string>

using namespace std;

int main() {  

    ios::sync_with_stdio(false);  
    cin.tie(nullptr);  

    string s;

    cin >> s;

    vector<int> v;
    vector<char> c;

    int temp = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            temp *= 10;
            temp += s[i] - '0';
        }

        else if (s[i] == '+' || s[i] == '-')
        {
            v.push_back(temp);
            temp = 0;
            c.push_back(s[i]);
        }
    }

    v.push_back(temp);

    int sum = v[0];
    bool isMinus = false;

    for (int i = 0; i < c.size(); i++)
    {
        if (c[i] == '-') isMinus = true;

        sum += isMinus ? -v[i + 1] : v[i + 1];
    }

    cout << sum;

    return 0;  
}