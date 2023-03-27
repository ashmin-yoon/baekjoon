#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE = 4000001;

bool isPrime[MAX_SIZE];
int N;
int cnt[MAX_SIZE];

void Init() {
	for (int i = 0; i < MAX_SIZE; i++)
	{
		isPrime[i] = true;
	}
}

void SetPrimeNumber(int n) {
	Init();
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i <= n; i++)
	{
		if (!isPrime[i]) continue;
		for (int j = 2; i*j <= n; j++)
		{
			isPrime[i*j] = false;
		}
	}
}

int main() {

	cin >> N;
	SetPrimeNumber(N);

	vector<int> prime_v;

	for (int i = 2; i <= N; i++)
	{
		if (isPrime[i])
			prime_v.push_back(i);
	}


	int start = 0; 			// index
	int end = -1;
	int sum = 0;
	int size = prime_v.size();

	while(start < size && end < size)
	{
		//cout << sum << endl;
		if (sum < N)
		{
			end++;
			sum += prime_v[end];
		}
		else if (sum == N)
		{
			cnt[N]++;
			end++;
			sum += prime_v[end];
		}
		else
		{
			sum -= prime_v[start];
			start++;
		}
	}

	cout << cnt[N];


	return 0;
}
