#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int cnt;

	cin >> cnt;

	while (cnt > 0)
	{
		int money;
		
		cin >> money;

		int q = money / 25;
		money %= 25;

		int d = money / 10;
		money %= 10;

		int n = money / 5;
		money %= 5;

		int p = money;

		cout << q << " " << d << " " << n << " " << p << endl;
		cnt--;
	}

	return 0;
}