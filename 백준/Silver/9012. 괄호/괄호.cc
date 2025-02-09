#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int cnt;

	cin >> cnt;

	for (int i = 0; i < cnt; i++)
	{
		stack<char> s;
		string str;

		cin >> str;

		bool isBreak = false;

		for (auto c : str)
		{
			if (c == '(')
			{
				s.push(c);
			}

			else
			{
				if (s.empty())
				{
					isBreak = true;
					break;
				}

				if (s.top() == '(') s.pop();
			}
		}

		if (s.empty() && !isBreak) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}


	return 0;
}