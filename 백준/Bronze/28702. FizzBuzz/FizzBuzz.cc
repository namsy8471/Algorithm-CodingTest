#include <iostream>
#include <string>

using namespace std;

void fizzBuzz(string s1, string s2, string s3)
{
	int num = 0;

	if (s1[0] != 'F' && s1[0] != 'B') {
		num = stoi(s1);
		num += 3;
	}

	else if (s2[0] != 'F' && s2[0] != 'B')
	{
		num = stoi(s2);
		num += 2;
	}

	else {
		num = stoi(s3);
		num += 1;
	}

	string s = "";

	if (num % 3 == 0) s += "Fizz";
	if (num % 5 == 0) s += "Buzz";

	if (s.empty()) cout << num;
	else cout << s;
}

int main()
{
	string s1, s2, s3;

	cin >> s1 >> s2 >> s3;

	fizzBuzz(s1, s2, s3);

	return 0;
}