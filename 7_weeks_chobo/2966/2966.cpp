#include <iostream>
using namespace std;

int main() {
	char a[3] = { 'A', 'B', 'C' };
	char b[4] = { 'B', 'A', 'B', 'C'};
	char c[6] = { 'C', 'C', 'A', 'A', 'B', 'B'};

	int score[3] = {0,0,0};

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		char tmp; cin >> tmp;
		if (a[i % 3] == tmp) score[0]++;
		if (b[i % 4] == tmp) score[1]++;
		if (c[i % 6] == tmp) score[2]++;
	}

	int Max(0);
	for (int i = 0; i < 3; i++) {
		Max = score[i] > Max ? score[i] : Max;
	}

	cout << Max << endl;
	if (Max == score[0]) cout << "Adrian" << endl;
	if (Max == score[1]) cout << "Bruno" << endl;
	if (Max == score[2]) cout << "Goran" << endl;

}