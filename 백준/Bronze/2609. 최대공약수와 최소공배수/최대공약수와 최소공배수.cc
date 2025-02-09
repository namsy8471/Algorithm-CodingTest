#include <iostream>

using namespace std;

int getLCM(int a, int b)
{
	if (a > b) return b == 0 ? a : getLCM(b, (a % b));
	else return a == 0 ? b : getLCM(a, b % a);
}

pair<int, int> getGCDAndLCM(int a, int b)
{
	int gcd, lcm;

	lcm = getLCM(a, b);
	gcd = a * b / lcm;

	return make_pair(lcm, gcd);
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