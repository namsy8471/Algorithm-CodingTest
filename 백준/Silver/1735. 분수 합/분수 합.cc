#include <iostream>

using namespace std;

int GCD(int a, int b)
{
    if (a >= b) return (a % b == 0) ? b : GCD(b, a % b);
    else return (b % a == 0) ? a : GCD(a, b % a);
}

int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}


int main() {
    
    int as, am, bs, bm;

    cin >> as >> am;
    cin >> bs >> bm;

    int s = (as * (LCM(am, bm) / am)) + (bs * (LCM(am, bm) / bm));
    int m = LCM(am, bm);

    cout << s / GCD(s, m) << ' ' << m / GCD(s, m);

    return 0;
}
