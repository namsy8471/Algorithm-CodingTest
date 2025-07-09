#include <iostream>

using namespace std;

unsigned long long power(unsigned long long a, unsigned long long b, unsigned long long c)
{
    if (b == 1) return a % c;

    unsigned long long val = power(a, b / 2, c);

    val = (val * val) % c;

    if (b % 2 != 0)
    {
        val = (val * a) % c;
    }

    return val;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
   
    unsigned long long a, b, c;

    cin >> a >> b >> c;

    unsigned long long ret = 1;

    if (b == 0)
        cout << 1 % c;
    else
        cout << power(a, b, c);

    return 0;  
}