#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int time = 0;
	for (int i = 1; N > 0; i++) {
		
		if (N < i) i = 1;
		time++;
		N -= i;
	}

	cout << time;


}

