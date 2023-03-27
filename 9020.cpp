#include <iostream>
#include <vector>

using namespace std;

vector<int> prime;

void SetPrime(int max) {
	prime.push_back(2);
	for (int i = 3; i <= max; i++) {
		bool is_prime = true;
		for (int j = 0; j < prime.size(); j++) {
			if (i % prime[j] == 0)
			{
				is_prime = false;
				break;
			}

			if (prime[j] * prime[j] > i)
				break;
		}

		if (is_prime)
			prime.push_back(i);
	}
}

bool IsPrime(int n) {
	//시작 0 끝 prime.size() - 1
	//중간 index = (시작 + 끝)/2
	int start = 0;
	int end = prime.size() - 1;
	int mid = (start + end) / 2;

	while(start < end) {
		mid = (start + end) / 2;

		// 숫자가 중간 값보다 클 때
		if (prime[mid] < n)
		{
			start = mid + 1;
		}
		else if (prime[mid] == n)
		{
			return true;
		}
		// 중간 값보다 작을 때
		else
		{
			end = mid - 1;
		}
	}

	if (prime[start] == n || prime[end] == n)
		return true;

	return false;
}

int main()
{
	int T;
	int num;
	SetPrime(10000);

	cin >> T;

	while(T--)
	{
		cin >> num;

		// 짝수 num은 (num/2 - a) + (num/2 + a) 로 나타낼 수 있다
		// 해당 풀이는 풀고나서 시간 단축을 위해 찾아봄
		for (int a = 0; a < num/2; a++) {
			if (IsPrime(num/2 - a) && IsPrime(num/2 + a))
			{
				cout << num/2-a << " " << num/2+a << endl;
				break;
			}
		}
		
	}


	return 0;
}
