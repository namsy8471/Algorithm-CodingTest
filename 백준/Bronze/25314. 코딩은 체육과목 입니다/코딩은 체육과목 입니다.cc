#include <iostream>

using namespace std;

int main()
{
	int bytes;
	cin >> bytes;

	for (int i = bytes; i >= 4; i -= 4)
		cout << "long ";
	
	cout << "int";

	return 0;
}