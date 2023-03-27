#include <iostream>

using namespace std;

int main() {

	int num;
	cin >> num;

	int division = 2;
	while(num > 1) 
	{	
		if (num % division == 0)
		{
			cout << division << endl;
			num /= division;
		}
		else
		{
			division++;
		}
	}

	return 0;
}
