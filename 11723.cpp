#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
const int MAX = 21;

int checked[MAX];
string command;
int number = 0;

enum Command {
	ADD,
	REMOVE,
	CHECK,
	TOGGLE,
	ALL,
	EMPTY
};

map<string, enum Command> commandSet;

void Clear() {
	for (int i = 1; i < MAX; i++) {
		checked[i] = false;
	}
}

void Toggle() {
	cin >> number;
	checked[number] = !checked[number];
}

void Add() {
	cin >> number;
	checked[number] = true;
}

void Remove() {
	cin >> number;
	checked[number] = false;
}

void Check() {
	cin >> number;
	if (checked[number])
	{
		cout << 1 << "\n";
	}
	else {
		cout << 0 << "\n";
	}
}

void All() {
	for (int i = 1; i < MAX; i++) {
		checked[i] = true;
	}
}

void Execute() {
	switch (commandSet[command])
	{
		case ADD:
			Add();
			break;
		case REMOVE:
			Remove();
			break;
		case CHECK:
			Check();
			break;
		case TOGGLE:
			Toggle();
			break;
		case ALL:
			All();
			break;
		case EMPTY:
			Clear();
			break;
		default:
			break;
	}
}

int main() {

	// 아래 속도 최적화 안해주면 시간초과
	cin.tie(NULL);
	ios::sync_with_stdio(false);

 	commandSet["add"] = ADD;
 	commandSet["remove"] = REMOVE;
 	commandSet["check"] = CHECK;
 	commandSet["toggle"] = TOGGLE;
 	commandSet["all"] = ALL;
 	commandSet["empty"] = EMPTY;
	int T;
	cin >> T;


	while(T--) {
		cin >> command;
		Execute();
	}
	return 0;
}
