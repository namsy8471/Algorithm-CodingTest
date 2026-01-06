#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;

    sort(targets.begin(), targets.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[1] == b[1]) {
            return a[0] < b[0];
        }

        return a[1] < b[1];
	});

    int end = -1;

    for (const auto& target : targets) {
        if (target[0] >= end) {
            answer++;
            end = target[1];
        }
	}

    return answer;
}