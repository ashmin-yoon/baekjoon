#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	string str;
	int count = 0;
	int sum = 0;
	while(T--)
	{
		cin >> str;	
		sum = 0;
		count = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'X') {
				count = 0;
			}
			else {
				count++;	
				sum += count;
			}
		}
		cout << sum << endl;
	}



	return 0;
}
