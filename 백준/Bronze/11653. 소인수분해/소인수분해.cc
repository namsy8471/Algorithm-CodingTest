#include <iostream>

using namespace std;

void Divide(int n)
{
	if (n == 1) return;

	for (int i = 2; i <= n; i++)
	{
		if (n % i != 0) continue;
		
		cout << i << endl;
		n /= i;
		i--;
	}
}

int main()
{
	int n;

	cin >> n;

	Divide(n);

	return 0;
}