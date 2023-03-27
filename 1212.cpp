#include <iostream>
#include <string>

using namespace std;

int main() {
	string binary;
	string octal;

	cin >> octal;

	
	for (int i = 0; i < octal.size(); i++) {
		switch(octal[i])
		{
			case '0':
				binary += "000";
				break;
			case '1':
				binary += "001";
				break;
			case '2':
				binary += "010";
				break;
			case '3':
				binary += "011";
				break;
			case '4':
				binary += "100";
				break;
			case '5':
				binary += "101";
				break;
			case '6':
				binary += "110";
				break;
			case '7':
				binary += "111";
				break;
		}
	}

	int startIndex = 0;
	for (int i = 0; i < binary.size(); i++) {
		if (binary[i] > '0')
		{
			startIndex = i;
			break;
		}
	}

	cout << binary.substr(startIndex);
	return 0;
}
