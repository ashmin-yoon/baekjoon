#include <iostream>
#include <string>
using namespace std;
const int MAX = 10;
// 
int k = 0;
char condition[MAX];
bool selected[MAX];
bool isFindMin = false;
bool isFindMax = false;


void PrintSelectionNumber() {
	for (int i = 0 ; i < k + 1; i++)
	{
		cout << selected[i];
	}
	cout << "\n";
}

bool CheckCondition(int preNumber, int target, int count) {
	int conditionIndex = count - 1;

	if (conditionIndex < 0) {
		return true;
	}

	switch (condition[conditionIndex]) {
		case '<':
			if (preNumber < target)
				return true;
			break;
		case '>':
			if (preNumber > target)
				return true;
			break;
	}

	return false;
}

void FindMin(int pick, int count, string strMin) {
	// 찾고나면 이후 작업 중단
	if (isFindMin)
		return;

	if (count == k + 1) {
		cout << strMin << endl;
		isFindMin = true;
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (selected[i])
			continue;
		// 컨디션 확인 해야함
		if (CheckCondition(pick, i, count) == false)
			continue;
		selected[i] = true;
		FindMin(i, count + 1, strMin + to_string(i));
		selected[i] = false;
	}
}

void FindMax(int pick, int count, string strMax) {
	// 찾고나면 이후 작업 중단
	if (isFindMax)
		return;

	if (count == k + 1) {
		cout << strMax << endl;
		isFindMax = true;
		return;
	}

	for (int i = 9; i >= 0; i--) {
		if (selected[i])
			continue;
		// 컨디션 확인 해야함
		if (CheckCondition(pick, i, count) == false)
			continue;
		selected[i] = true;
		FindMax(i, count + 1, strMax + to_string(i));
		selected[i] = false;
	}
}


int main() {
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> condition[i];
	}

	FindMax(0, 0, "");
	FindMin(0, 0, "");
	return 0;
}
