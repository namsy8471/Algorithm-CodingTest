#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s;

	cin >> s;

	string comp = s;
	reverse(comp.begin(), comp.end());

	int ret = (s == comp) ? 1 : 0;

	cout << ret << endl;


	return 0;
}