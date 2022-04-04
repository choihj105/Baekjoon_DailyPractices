#include <iostream>
using namespace std;
int main() 
{
	char yut[5] = { 'E', 'A', 'B', 'C', 'D' };
	
	int n = 3;
	while (n--) {
		bool deung; int tmp = 0;
		for (int i = 0; i < 4; i++) {
			cin >> deung;
			if (!deung) tmp++;
		}

		cout << yut[tmp] << '\n';
	}
}