#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<unsigned int> generatePrimes(const unsigned int limit) {
    vector<bool> isPrime(limit + 1, true);
    vector<unsigned int> primes;

    isPrime[0] = isPrime[1] = false;

    for (unsigned int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (unsigned int j = i * 2; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return primes;
}

bool isPrime(unsigned int n, const vector<unsigned int> smallPrimes)
{
    if (n < 2) return false;
    unsigned int root = sqrt(n);
    for (auto prime : smallPrimes) {
        if (prime > root) break;
        if (n % prime == 0) return false;
    }

    return true;
}

unsigned int findNextPrime(unsigned int n, const vector<unsigned int>& smallPrimes) {
    while (!isPrime(n, smallPrimes)) {
        n++;
    }
    return n;
}

int main() {
    
    int cnt;

    cin >> cnt;

    const unsigned int LIMIT = sqrt(4e9) + 1;
    vector<unsigned int> smallPrimes = generatePrimes(LIMIT);

    for (int i = 0; i < cnt; i++)
    {
        unsigned int n;
        cin >> n;

        cout << findNextPrime(n, smallPrimes) << '\n';
    }

    return 0;
}