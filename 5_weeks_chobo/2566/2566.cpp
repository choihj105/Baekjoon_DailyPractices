#include <iostream>
using namespace std;

int main() {

	int cIdx, rIdx;
	int max = 0 ;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int tmp; cin >> tmp;

			if (max < tmp) {
				max = tmp;
				cIdx = i + 1;
				rIdx = j + 1;
			}
		}
	}
	
	cout << max << endl;
	cout << cIdx<< ' ' << rIdx <<endl;


}