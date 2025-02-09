#include <iostream>

using namespace std;

int getGCD(int a, int b)
{
	if (a > b) return b == 0 ? a : getGCD(b, (a % b));
	else return a == 0 ? b : getGCD(a, b % a);
}

pair<int, int> getGCDAndLCM(int a, int b)
{
	int gcd, lcm;

	gcd = getGCD(a, b);
	lcm = a * b / gcd;

	return make_pair(gcd, lcm);
}

int main()
{
	int a, b;

	cin >> a >> b;

	pair<int, int> ret = getGCDAndLCM(a, b);

	cout << ret.first << '\n';
	cout << ret.second;

	return 0;
}