#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	int cnt;
	int ret = 0;
	
	cin >> cnt;

	while (cnt > 0)
	{
		string str;
		cin >> str;
		
		set<char> s;
		bool isGroup = true;

		for (int i = 0; i < str.length(); i++)
		{
			if(i == 0)	s.insert(str[i]);
			else
			{
				if (str[i - 1] == str[i]) continue;
				else {
					auto isEnd =  s.find(str[i]);
					if (isEnd != s.end()) {
						isGroup = false;
						break;
					}
					else s.insert(str[i]);
				}
			}
		}

		if (isGroup) ret++;
		cnt--;
	}

	

	cout << ret;

	return 0;
}