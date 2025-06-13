#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

int Check(std::set<int>* set, int n)
{
	int ret;
	if (set->find(n) != set->end()) ret = 1;
	else ret = 0;

	return ret;
}

void CheckCommand(string s, int n, set<int>* set)
{
	if (s == "add")
	{
		set->insert(n);
	}

	else if (s == "remove")
	{
		set->erase(n);
	}

	else if (s == "check")
	{
		cout << Check(set, n) << '\n';
	}

	else if (s == "toggle")
	{
		if (Check(set, n)) set->erase(n);
		else set->insert(n);
	}

	else if (s == "all")
	{
		for (int i = 1; i <= 20; i++)
			set->insert(i);
	}

	else if (s == "empty")
	{
		set->clear();
	}
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int cnt;

	cin >> cnt;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	set<int> set;

	while (cnt--)
	{
		string s;

		cin >> s;

		int n = 0;

		if(s != "all" && s != "empty")
			cin >> n;

		CheckCommand(s, n, &set);
	}

	return 0;
}