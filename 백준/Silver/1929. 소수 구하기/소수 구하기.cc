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

void printPrime(unsigned int fromN, unsigned int toN, const vector<unsigned int>& smallPrimes) {
    
    for (auto prime : smallPrimes) {
        if (prime < fromN) continue;
        if (prime > toN) break;

        cout << prime << '\n';
    }
}

int main() {
    
    int fromN, toN;

    cin >> fromN >> toN;

    vector<unsigned int> smallPrimes = generatePrimes(toN);
    
    printPrime(fromN, toN, smallPrimes);
    
    return 0;
}