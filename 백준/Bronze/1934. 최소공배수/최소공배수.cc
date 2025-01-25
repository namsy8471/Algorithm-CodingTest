#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int GCD(int a, int b)
{
    if (a >= b) return (a % b == 0) ? b : GCD(b, a % b);
    else return (b % a == 0) ? a : GCD(a, b % a);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt;

    cin >> cnt;

    for (int i = 0; i < cnt; i++)
    {
        int a, b;

        cin >> a >> b;

        cout << (a * b) / GCD(a, b) << '\n';
    }

    return 0;
}