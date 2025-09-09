#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n){ 
	if( n < 2) return false;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0){
			return false;
		}
	}
	

	return true;
}

int main() {
	
	vector<int> primes;
	vector<int> superprimes;

	int n;
	cin >> n;


	int i = 2;
	while (superprimes.size() < n)
	{
		if (isPrime(i))
		{
			primes.push_back(i);
			if (isPrime(primes.size()))
			{
				superprimes.push_back(i);
			}	
		}
		i++;
	}
	

	cout << superprimes[n-1] << endl;
	return 0;
}