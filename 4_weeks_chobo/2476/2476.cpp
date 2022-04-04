#include <iostream>
using namespace std;

int main() 
{
	int n; cin >> n;
	int total = 0;
	for (int k = 0; k < n; k++) {
		int arr[7] = { 0, };
	
		// 1. 입력
		for (int j = 0; j < 3; j++) {
			int tmp;
			cin >> tmp;
			arr[tmp]++;
		}

		// 2. 숫자 판별
		for (int i = 6; i > 0; i--) {
			if (arr[i] == 3) {
				total = total < 10000 + 1000 * i ? 10000 + 1000 * i : total;
				break;
			}
			else if (arr[i] == 2) {
				total = total < 1000 + 100 * i ? 1000 + 100 * i : total;
				break;
			}
			else if (arr[i] == 1)
			{
				total = total < 100 * i ? 100 * i : total;
			}
		}

	}
	
	cout << total;
	
}