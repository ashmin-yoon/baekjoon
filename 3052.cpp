#include <iostream>

using namespace std;

int main() {

	int arr[10];
	bool flag[42];
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 42; i++) {
		flag[i] = false;
	}

    int count = 0;
	for (int i = 0; i < 10; i++) {
        if (flag[arr[i] % 42] == false){
            flag[arr[i] % 42] = true;
            count++;
        }
	}

	cout << count << endl;

	return 0;
}
