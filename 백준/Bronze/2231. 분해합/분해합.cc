#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int ret = 0;

	for (int i = 0; i < n; i++)
	{
		string s = to_string(i);

		ret = i;
		for (int j = 0; j < s.length(); j++)
		{
			ret += s[j] - '0';
		}

		if (n != ret) 
		{
			ret = 0;
			continue; 
		}

		ret = i;
		break;
	}

	cout << ret << endl;

	return 0;
}