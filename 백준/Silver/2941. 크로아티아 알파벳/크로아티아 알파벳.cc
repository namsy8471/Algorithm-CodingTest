#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s;

	cin >> s;

	int cnt = s.length();

	for (int i = 1; i < s.length(); i++)
	{
		switch (s[i])
		{
		case '=':
			if (i > 1 && s[i - 1] == 'z' && s[i - 2] == 'd') cnt--;
		case '-':
			cnt--;
			break;
		case 'j':
			if (s[i - 1] == 'l' || s[i - 1] == 'n')
				cnt--;
			break;

		default:
			break;
		}
	}

	cout << cnt;

	return 0;
}