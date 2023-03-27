#include <iostream>
#include <vector>
using namespace std;


// 1 ~ 49 에서 6개선택
vector<int> numVec;
int k;
vector<int> selected;

void Solution(int picked, int count) {
	if (count == 6)	
	{
		for (int i = 0; i < 6; i++) {
			cout << selected[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = picked; i < k; i++) {
		selected.push_back(numVec[i]);
		Solution(i + 1, count + 1);
		selected.pop_back();
	}
}

int main() {
	int tmp;
	while(true)
	{
		cin >> k;
		if(k == 0) break;
		numVec.clear();
		for (int i = 0; i < k; i++)	
		{
			cin >> tmp;
			numVec.push_back(tmp);	
		}
		Solution(0, 0);
		cout << "\n";
	}


	return 0;
}
