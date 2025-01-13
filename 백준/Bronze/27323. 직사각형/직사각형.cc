#include <iostream>

using namespace std;

int GetArea(int w, int h)
{
	return w * h;
}

int main()
{
	int w, h;

	cin >> w;
	cin >> h;

	int area = GetArea(w, h);
	cout << area << endl;

	return 0;
}