#include <iostream>

using namespace std;

long long GCD(long long a, long long b)
{
    if (a >= b) return (a % b == 0) ? b : GCD(b, a % b);
    else return (b % a == 0) ? a : GCD(a, b % a);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;

    cin >> a >> b;

    cout << (a * b) / GCD(a, b) << '\n';
    

    return 0;
}