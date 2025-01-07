#include <iostream>
#include <string>

using namespace std;

int main()
{
	int cnt;

	cin >> cnt;

	while (cnt > 0)
	{
		string s;
		cin >> s;
		cout << s[0] << s[s.length() - 1] << endl;

		cnt--;
	}

	return 0;
}