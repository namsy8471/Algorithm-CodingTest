#include <iostream>

int GetValFromZSearch(int N, int row, int col)
{    
    int ret = 0;

    while (N > 0)
    {
        int half = 1 << (N - 1);
        int size = half * half;

        int idx = (row < half ? 0 : 2)
            + (col < half ? 0 : 1);    
        
        ret += size * idx;
        
        if (row >= half) row -= half;
        if (col >= half) col -= half;

        N--;
    }

    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, r, c;

    std::cin >> N >> r >> c;

    std::cout << GetValFromZSearch(N, r, c);

    return 0;  
}