#include <iostream>
#include <algorithm>
using namespace std;

// sortingµ» ≥≠¿Ô¿ÃµÈ O(N) + sort O(nlgn) = O(nlgn)
int main() {
	int sum(0); int dwarf[9];

	for (int i = 0; i < 9; i++) {
		cin >> dwarf[i];
		sum += dwarf[i];
	}
	sum -= 100;

	sort(dwarf, dwarf+9);

	int lPivot = 0; int rPivot = 8;
	while (rPivot > lPivot) {
		int tmp = dwarf[lPivot] + dwarf[rPivot];
		
		if (tmp == sum) break;
		else if (tmp > sum) rPivot--;
		else lPivot++;
	}

	for (int i = 0; i < 9; i++) {
		if (i == lPivot || i == rPivot) continue;
		cout << dwarf[i] << '\n';
	}
	
} 