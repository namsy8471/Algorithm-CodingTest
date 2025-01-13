#include <iostream>

using namespace std;

void Discrimination(int a, int b)
{
	if (a % b == 0) cout << "multiple" << endl;
	else if (b % a == 0) cout << "factor" << endl;
	else cout << "neither" << endl;
}

int main()
{
	while (true)
	{
		int a, b;

		cin >> a >> b;

		if (a == 0 && b == 0) break;
		
		Discrimination(a, b);
	}
	
	return 0;
}