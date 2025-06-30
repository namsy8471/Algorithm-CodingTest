#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long b;

    cin >> n >> m >> b;

    vector<int> land(n * m);
    int min_h = 256, max_h = 0;

    for (int i = 0; i < n * m; ++i) {
        cin >> land[i];
        if (land[i] < min_h) min_h = land[i];
        if (land[i] > max_h) max_h = land[i];
    }
    
    int min_time = INT_MAX;
    int result_height = 0;

    for (int h = 0; h <= 256; ++h) {
        int to_remove = 0;
        int to_add = 0;

        for (int block_height : land) {
            if (block_height > h) {
                to_remove += block_height - h;
            }
            else if (block_height < h) {
                to_add += h - block_height;
            }
        }

        if (b + to_remove >= to_add) {
            int current_time = to_remove * 2 + to_add * 1;

            if (current_time <= min_time) {
                min_time = current_time;
                result_height = h;
            }
        }
    }

    cout << min_time << " " << result_height << endl;

    return 0;  
}