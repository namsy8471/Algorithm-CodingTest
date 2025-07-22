#include <iostream>
#include <vector>

using namespace std;

void print(const vector<vector<int>>& v)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << v[i][j] << ' ';
        cout << '\n';
    }
}

bool isValid(const vector<vector<int>>& v, int row, int col, int num)
{
    for (int i = 0; i < 9; i++) {
        if (v[row][i] == num) return false;
        if (v[i][col] == num) return false;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (v[i + startRow][j + startCol] == num)
            {
                return false;
            }
        }
    }

    return true;
}

bool backtrack(vector<vector<int>>& v)
{
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++)
        {
            if (v[row][col] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (isValid(v, row, col, num))
                    {
                        v[row][col] = num;

                        if (backtrack(v)) {
                            return true;
                        }

                        v[row][col] = 0;
                    }
                }

                return false;
            }
        }
    }

    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


    vector<vector<int>> v(9, vector<int>(9, 0));

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> v[i][j];

    if (backtrack(v))
    {
        print(v);
    }

    return 0;
}