#include <iostream>

using namespace std;

int first_game[][2] = { {5000000, 1}, {3000000, 2}, {2000000, 3}, {500000, 4}, {300000, 5}, {100000, 6} };
int second_game[][2] = { {5120000, 1}, {2560000, 2}, {1280000, 4}, {640000, 8}, {320000, 16} };

int GetFirstGameMoney(int grade) {
	if (grade == 0)
		return 0;

	for (int i = 0; i < 6; i++) {
		grade -= first_game[i][1];
		if (grade <= 0) {
			return first_game[i][0];
		}
	}
	
	return 0;
}

int GetSecondGameMony(int grade) {
	if (grade == 0)
		return 0;

	for (int i = 0; i < 5; i++) {
		grade -= second_game[i][1];
		if (grade <= 0) {
			return second_game[i][0];
		}
	}

	return 0;
}

int main() {
	int num = 0;
	cin >> num;
	int* first_grade;
	int* second_grade;

	first_grade = new int [num];
	second_grade = new int [num];

	for (int i = 0; i < num; i++) {
		cin >> first_grade[i] >> second_grade[i];
	}

	for (int i = 0; i < num; i++) {
		cout << GetFirstGameMoney(first_grade[i]) + GetSecondGameMony(second_grade[i]) << endl;
	}

	delete [] first_grade;
	delete [] second_grade;
	return 0;
}
