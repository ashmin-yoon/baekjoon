#include <iostream>
#include <vector>
using namespace std;



int main() {
	vector<int> v(5);

	int tmp;
	for (int i = 0; i < 5; i++) {
		cin >> v[i];
	}


	int num = 1;
	int count = 0;
	while(true) {
		count = 0;
		for (int i = 0; i < v.size(); i++) {
			if (num % v[i] == 0)
			{
				count++;
			}
		}	

		if (count >= 3)
		{
			break;
		}

		num++;
	}

	cout << num << endl;

	return 0;
}
