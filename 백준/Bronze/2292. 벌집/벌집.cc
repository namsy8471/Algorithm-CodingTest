#include <iostream>

using namespace std;

int main()
{
	int x;

	cin >> x;

	// 0 -> 6 -> 12 -> 18
	// 1(1) -> 2~7(2) -> 8~19(3) -> 20~37(4)

	int ret = 1;
	int cnt = 1;

	while (x > ret)
	{
		ret += 6 * cnt;
		cnt++;
	}

	cout << cnt;
	
	return 0;
}