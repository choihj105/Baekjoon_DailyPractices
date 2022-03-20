#include <iostream>
#include <string>
using namespace std;

int main() {
	
	string A;
	int cnt = 0;
	getline(cin, A);


	for (int i = 0; i < A.length(); i++) {
		if (A[i] == ' ') ++cnt;
	}

	if (A.front() == ' ') --cnt;
	if (A.back() != ' ') ++cnt;
	
	cout << cnt;
}