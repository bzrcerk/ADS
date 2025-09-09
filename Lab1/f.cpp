#include <iostream>
#include <vector>

using namespace std;

int main() {
	int num;
	cin >> num;

	vector<int> primes;

	for (int i = 2; i < 100000; i++)
	{
		bool isPrime = true;

		for (int j = 2; j < 1000; j++)
		{
			if (i % j == 0 && i != j) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			primes.push_back(i);
		}
	}
	

	cout << primes[num-1] << endl;

	return 0;
}