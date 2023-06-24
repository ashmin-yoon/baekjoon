#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

bool adj[MAX_SIZE][MAX_SIZE];
int N;

void Input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> adj[i][j];
		}
	}
}

void Warshall() {
	// i -> j 경로는 
	// i -> k -> j 가능하면 i j 가능
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
			}
		}
	}
}

void Print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << adj[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();
	Warshall();
	Print();


	return 0;
}
