#include <iostream>
#include <vector>

using namespace std;

vector<int> prime_num;

void SetPrimeNumber(int max)
{
	prime_num.push_back(2);

	for (int i = 3; i <= max; i++)
	{
		bool isPrime = true;
		for (int j = 0; j < prime_num.size(); j++) 
		{
			// 소수 아님
			if (i % prime_num[j] == 0) {
				isPrime = false;
				break;
			}
			
			// 탐색 범위 지정
			if (prime_num[j]*prime_num[j] > i)
			{
				break;
			}
		}

		if (isPrime)
		{
			prime_num.push_back(i);
		}
	}

}

int main() 
{
	SetPrimeNumber(123456 * 2);

	int input;
	cin >> input;
	while(input)
	{
		int min_value = input + 1;
		int max_value = input * 2;
		int count = 0;

		for (int i = 0; i < prime_num.size(); i++)
		{
			if (min_value <= prime_num[i] && prime_num[i] <= max_value)
				count++;
		}
		cout << count << endl;
		cin >> input;
	}

	return 0;
}
