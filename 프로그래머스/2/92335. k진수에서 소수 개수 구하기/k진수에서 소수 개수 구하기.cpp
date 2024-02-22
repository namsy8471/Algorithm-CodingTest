#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> conv(int n, int k)
{
    vector<int> ret;
    while(n)
    {
        ret.push_back(n % k);
        n /= k;
    }
    
    reverse(ret.begin(), ret.end());
    return ret;
}

int isPrime(long long num)
{
    if (num <= 1) return 0;
    for(long long i = 2; i * i <= num; i++)
    {
        if(num % i == 0) return 0;
    }
    
    return 1;
}

int solution(int n, int k) {
    int answer = 0;
    
    vector<int> v = conv(n,k);
    long long cur = 0;
    
    for(int digit : v)
    {
        if(digit == 0)
        {
            answer += isPrime(cur);
            cur = 0;
            continue;
        }
        cur = 10 * cur + digit;
    }
    
    answer += isPrime(cur);
    
    return answer;
}