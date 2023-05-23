#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 100000;

int N;

typedef struct {
	int age;
	int seq;	
	string name;
}Member;

Member member[MAX_SIZE];

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N;
	int age;
	for (int i = 0; i < N; i++) {
		cin >> member[i].age;
		cin >> member[i].name;
		member[i].seq = i;
	}
}

bool cmp(Member& m1, Member& m2) {
	if (m1.age == m2.age)
	{
		return m1.seq < m2.seq;
	}

	return m1.age < m2.age;
}

int main() {
	FastIO();
	Input();

	sort(member, member + N, cmp);

	for (int i = 0; i < N; i++) {
		cout << member[i].age << " " << member[i].name << "\n";
	}


	return 0;
}

