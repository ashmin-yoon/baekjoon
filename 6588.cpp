#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

const int MAX_VALUE = 1000000;

vector<int> primeNumbers;

int FindLastValueIndexLessThanNumber(int n)
{
	int low = 0;
	int high = primeNumbers.size() - 1;

	int mid;
	while(low <= high)
	{
		mid = (low + high) / 2;
		//printf("mid %d\tlow %d\thigh %d\n", primeNumbers[mid], primeNumbers[low], primeNumbers[high]);
		if (primeNumbers[mid] > n)
		{
			high = mid - 1;
		} 
		else if (primeNumbers[mid] < n)
		{
			low = mid + 1;
			if (n <= primeNumbers[mid + 1])
			{
				return mid;
			}
		}
		else 
		{
			return mid - 1;
		}
	}
	return high;
}

bool GoldbachFunc(int n)
{
	int right = FindLastValueIndexLessThanNumber(n);
	int left = 0;

	while(left <= right)
	{
		int sum = primeNumbers[left] + primeNumbers[right];
		if (sum == n)
		{
			printf("%d = %d + %d\n", n, primeNumbers[left], primeNumbers[right]);
			return true;
		}
		else if (sum > n)
		{
			right--;	
		}
		else
		{
			left++;
		}
	}
	
	return false;
}

void SetPrimeNumbers()
{
	primeNumbers.clear();
	primeNumbers.push_back(2);
	primeNumbers.push_back(3);

	bool isPrime;
	for (int i = 5; i <= MAX_VALUE; i++) 
	{
		isPrime = true;
		for (int j = 0; j < primeNumbers.size(); j++) 
		{
			if (primeNumbers[j] * primeNumbers[j] > i) 
			{	
				break;
			}

			if (i % primeNumbers[j] == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
		{
			primeNumbers.push_back(i);
		}
	}
}


int main() {	
	int num;
	SetPrimeNumbers();

	while(true) {
		scanf("%d", &num);
		if (num == 0)
			break;
		
		if (GoldbachFunc(num) == false)
			cout << "Goldbach's conjecture is wrong.\n";
	}

	return 0;
}
