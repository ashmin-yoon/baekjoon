#include <iostream>

using namespace std;

char map[8][8];

int main() {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> map[i][j];
		}
	}

	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0 && j % 2 == 0 && map[i][j] == 'F')	count++;
			if (i % 2 == 1 && j % 2 == 1 && map[i][j] == 'F')	count++;
		}
	}

	cout << count << endl;
	return 0;
}
