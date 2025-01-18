#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;

	cin >> n;

	vector<int> v;

	for (int i = 666; i < 2147483647; i++)
	{
		string str = to_string(i);
		if (str.find("666") != str.npos)
			v.push_back(stoi(str));

		if (v.size() >= n) break;
	}

	cout << v[v.size() - 1] << endl;
	
	return 0;
}