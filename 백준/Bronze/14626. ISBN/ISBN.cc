#include <iostream>
#include <vector>

#define Digit 13

using namespace std;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<char> v(Digit, '0');
	int sum = 0;
	bool isOdd;

	for (int i = 0; i < Digit; i++) {
		cin >> v[i];
		
		if (v[i] != '*')
			sum += i % 2 == 0 ?
			(v[i] - '0') : 3 * (v[i] - '0');
		else
			isOdd = i % 2 == 0 ?
			true : false;
	}

	int ret = -1;

	for (int i = 0; i <= 9; i++)
	{
		int weight = isOdd ? i : i * 3;

		if ((sum + weight) % 10 == 0) {
			ret = i;
			break;
		}
	}

	cout << ret << endl;

	return 0;
}