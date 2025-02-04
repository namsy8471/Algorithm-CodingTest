#include <iostream>
#include <vector>

using namespace std;

vector<bool> sieveOfEratosthenes(int limit, vector<int>& primes)
{
	vector<bool> isPrime(limit + 1, true);

	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i * i <= limit; i++)
	{
		if (!isPrime[i]) continue;
		for (int j = i * i; j <= limit; j += i)
			isPrime[j] = false;
	}

	for(int i = 2; i <= limit; i++)
		if(isPrime[i]) primes.push_back(i);

	return isPrime;
}

int getHowManyGoldbach(const int num, const vector<int>& primes, const vector<bool>& isPrime)
{
	int ret = 0;

	for (int i = 0; i < primes.size(); i++)
	{
		if (primes[i] > num / 2) break;
		if (isPrime[num - primes[i]]) ret++;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cnt;

	cin >> cnt;

	vector<int> primes;
	vector<bool> isPrime = sieveOfEratosthenes(1e6, primes);

	for (int i = 0; i < cnt; i++)
	{
		int num;
		cin >> num;

		cout << getHowManyGoldbach(num, primes, isPrime) << '\n';
	}

	return 0;
}