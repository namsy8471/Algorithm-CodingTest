#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void Cal(int& avg, int& median, int& freq, int& diff, vector<int>& v)
{
	if (v.size() == 1)
	{
		avg = v[0];
		median = v[0];
		freq = v[0];
		diff = 0;

		return;
	}

	vector<int> counts(8001, 0);

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		avg += v[i];
		counts[v[i] + 4000]++;
	}

	// 3. 최빈값
	int max_freq = 0;
	for (int i = 0; i <= 8000; ++i) {
		if (counts[i] > max_freq) {
			max_freq = counts[i];
		}
	}

	vector<int> modes;
	for (int i = 0; i <= 8000; ++i) {
		if (counts[i] == max_freq) {
			modes.push_back(i - 4000);
		}
	}

	freq = (modes.size() > 1) ? modes[1] : modes[0];

	float rnd = round((float) avg / v.size());
	avg = (int) rnd;
	median = v[v.size() / 2];
	diff = v.back() - v.front();
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int cnt;

	cin >> cnt;

	vector<int> v;

	while (cnt--)
	{
		int n;
		cin >> n;
		v.push_back(n);
	}

	int avg = 0, median = 0, freq = 0, diff = 0;

	Cal(avg, median, freq, diff, v);

	cout << avg << endl;
	cout << median << endl;
	cout << freq << endl;
	cout << diff << endl;

	return 0;
}