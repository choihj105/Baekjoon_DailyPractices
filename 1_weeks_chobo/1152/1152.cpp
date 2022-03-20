#include <iostream>
#include <string>
using namespace std;

int main() {

	int cnt = 0;
	string str;
	
	while (cin >> str) {
		++cnt;
	}

	cout << cnt;
}

//string A;
//int cnt = 0;
//getline(cin, A);


//for (int i = 0; i < A.length(); i++) {
//	if (A[i] == ' ') ++cnt;
//}

//if (A.front() == ' ') --cnt;
//if (A.back() != ' ') ++cnt;
//