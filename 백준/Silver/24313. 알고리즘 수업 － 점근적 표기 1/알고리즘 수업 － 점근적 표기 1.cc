#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	int a1, a2;
	int c;
	int n;

	cin >> a1 >> a2;
	cin >> c;
	cin >> n;

	bool ret = (a1 * n) + a2 <= c * n;

	while (n < 100 && ret)
	{
		if ((a1 * n) + a2 > c * n) ret = false;
		n++;
	}

	cout << ret << endl;

	return 0;
}