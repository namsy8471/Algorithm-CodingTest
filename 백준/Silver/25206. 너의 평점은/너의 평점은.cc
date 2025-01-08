#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	int cnt = 20;
	
	float wholeGrade = 0;
	int credits = 0;

	while (cnt > 0)
	{
		string subName;
		float credit;
		string grade;
		float gradeToNum = 0;

		cin >> subName >> credit >> grade;

		switch (grade[0])
		{
		case 'A':
			gradeToNum = 4;
			break;
		case 'B':
			gradeToNum = 3;
			break;
		case 'C':
			gradeToNum = 2;
			break;
		case 'D':
			gradeToNum = 1;
			break;
		case 'P':
			gradeToNum = 0;
			break;
		case 'F':
			gradeToNum = 0;
			break;
		default:
			break;
		}

		if (grade.length() > 1 &&
			grade[1] == '+') gradeToNum += 0.5f;

		if (grade[0] != 'P') {
			wholeGrade += gradeToNum * credit;
			credits += credit;
		}

		cnt--;
	}

	float average = wholeGrade / (float)credits;
	
	cout << average;

	return 0;
}