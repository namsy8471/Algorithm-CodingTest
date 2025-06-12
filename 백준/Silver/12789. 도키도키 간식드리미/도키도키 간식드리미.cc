#include <iostream>
#include <queue>
#include <stack>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	queue<int> q;
	stack<int> s;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push(x);
	}

	int idx = 1;

	while (idx < n + 1)
	{
		if (!s.empty() && s.top() == idx)
		{
			s.pop();
			idx++;
			continue;
		}

		if (!q.empty())
		{
			if (q.front() == idx)
			{
				q.pop();
				idx++;
				continue;
			}

			else
			{
				s.push(q.front());
				q.pop();
				continue;
			}
		}
		else if (!s.empty()) break;
	}

	if (q.empty() && s.empty())
		cout << "Nice" << endl;
	else
		cout << "Sad" << endl;

	return 0;
}