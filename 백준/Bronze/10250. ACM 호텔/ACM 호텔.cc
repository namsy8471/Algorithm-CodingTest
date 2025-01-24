#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt;

    cin >> cnt;

    for (int i = 0; i < cnt; i++)
    {
        int h, w, n;

        cin >> h >> w >> n;

        int retH = (n % h == 0) ? h : n % h;
        int retW = (n % h == 0) ? n / h : n / h + 1;

        cout << (retH * 100) + retW << '\n';
    }


    return 0;
}