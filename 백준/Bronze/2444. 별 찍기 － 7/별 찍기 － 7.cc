#include <iostream>
#include <string>

using namespace std;

int main()
{
	int cnt;

	cin >> cnt;

	for (int i = 0; i < cnt * 2 - 1; i++)
	{
		if (i < cnt - 1)
		{
			int space = 0;

			for (int j = i; j < cnt - 1; j++)
			{
				cout << " ";
				space++;
			}

			for (int k = 0; k < ((cnt - 1) - space) * 2 + 1; k++)
			{
				cout << "*";
			}
		}

		else
		{
			int space = 0;

			for (int j = i; j > cnt - 1; j--)
			{
				cout << " ";
				space++;
			}

			for (int k = 0; k < ((cnt - 1) - space) * 2 + 1; k++)
			{
				cout << "*";
			}
		}

		cout << endl;
	}

	return 0;
}