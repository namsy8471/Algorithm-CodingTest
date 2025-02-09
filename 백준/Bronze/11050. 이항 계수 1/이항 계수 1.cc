#include <iostream>

using namespace std;

int getCombination(int n, int k)
{
	int ret;

	int pickCnt = 1;
	int kFactorial = 1;

	for (int i = n; i > n - k; i--) pickCnt *= i;
	for (int i = 2; i <= k; i++) kFactorial *= i;

	ret = pickCnt / kFactorial;

	return ret;
}

int main()
{
	int n, k;

	cin >> n >> k;
	cout << getCombination(n, k);

	return 0;
}