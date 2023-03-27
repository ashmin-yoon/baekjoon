#include <iostream>

using namespace std;

int a_count[10];
int b_count[10];

int main() {

	string a, b;
	cin >> a >> b;

	long long sum = 0;
	for (int i = 0; i < a.size(); i++)
	{
		a_count[a[i] - '0']++;
		
	}

	for (int i = 0; i < b.size(); i++)
	{
		b_count[b[i] - '0']++;
	}


	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int tmp = i * j * a_count[i] * b_count[j];
			sum += tmp;
		}
	}
	cout << sum;

	return 0;
}
