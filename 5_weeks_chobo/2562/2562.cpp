#include <iostream>
using namespace std;

int main() {

	int idx;
	int max = 0;

	for (int i = 0; i < 9; i++) {
		int tmp;
		cin >> tmp;

		if (max < tmp) {
			max = tmp;
			idx = i + 1; // 0��°�� �ƴ� 1��°���� ����
		}
	}
	cout << max << endl;
	cout << idx << endl;
}