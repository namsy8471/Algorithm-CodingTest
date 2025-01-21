#include <iostream>
#include <map>

using namespace std;

int main() {

    map<int, int> m;

    long long ret = 1;

    for (int i = 0; i < 3; i++)
    {
        int n;
        cin >> n;
        ret *= n;
    }

    while (ret > 0)
    {
        m[ret % 10]++;
        ret /= 10;
    }

    for (int i = 0; i < 10; i++)
        cout << m[i] << '\n';

    return 0;
}