#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a, b, c;
	int ret;

	cin >> a >> b >> c;

	int sides[] = {a, b, c};
	sort(sides, sides + 3);

	ret = sides[0] + sides[1];

	if (sides[2] >= sides[1] + sides[0])
		ret += sides[1] + sides[0] - 1;
	else ret += sides[2];

	cout << ret << endl;

	return 0;
}