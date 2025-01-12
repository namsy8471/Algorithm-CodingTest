#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int limit;
	int ret;

	cin >> limit;

	// 0 -> 1     -> 2     -> 3     -> 4     -> 5
	// 2 -> 3 (1) -> 5 (2) -> 9 (4) -> 17(8) -> 33(16)
	
	ret = pow(2, limit) + 1;
	ret = pow(ret, 2);

	cout << ret;

	return 0;
}