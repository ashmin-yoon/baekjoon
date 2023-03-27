#include <iostream>
#include <vector>
#define ARR_SIZE 1000001

using namespace std;

vector<int> prime_num;

void SetPrimeNum(int end) {
	prime_num.push_back(2);
	prime_num.push_back(3);

	for (int num = 5; num <= end; num++)
	{
		bool check = true;
		for (int i = 0; i < prime_num.size(); i++)
		{
			int n = prime_num[i];
			if (n*n > num)
				break;

			if(num % prime_num[i] == 0)
			{
				check = false;
				break;
			}
		}

		if (check)
			prime_num.push_back(num);
	}
}

int main() 
{

	int start;
	int end;

	cin >> start;
	cin >> end;

	SetPrimeNum(end);

	for (int i = 0; i < prime_num.size(); i++) {
		if (start <= prime_num[i] && prime_num[i] <= end)
			cout << prime_num[i] << endl;
	}

	return 0;
}
