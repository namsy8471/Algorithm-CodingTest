#include <iostream>
#include <cmath>

using namespace std;

int Climbing(int up, int down, int dest)
{
	double ret = (double)(dest - down) / (double)(up - down);
	return ceil(ret);
}

int main()
{
	int a, b, v;

	cin >> a >> b >> v;

	int ret = Climbing(a, b, v);

	cout << ret;

	
	return 0;
}