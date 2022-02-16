// #11723
/*

i:  1<= M <= 3,000,000, M개의 줄 수행 연산, 1<=x<=20

o:

sol)
1. class
2. bit mask

*/

// 1. class
#include <iostream>
#include <string>
using namespace std;

class Set {

private:
	bool *ptr;

public:
	Set(bool *p = 0) : ptr(p){
		for (int i = 0; i <= 20; i++) ptr[i] = false;
	}

	~Set() {
		delete ptr;
	}

	void add(int n) { ptr[n] = true; }

	void remove(int n) { ptr[n] = false; }

	void check(int n) {
		if (ptr[n]) cout << 1 << '\n';
		else cout << 0 << '\n';
	}

	void toggle(int n) {
		ptr[n] == true ? ptr[n] = false : ptr[n] = true;
	}
	
	void all() {
		for (int i = 0; i <= 20; i++) ptr[i] = true;
	}

	void empty() {
		for (int i = 0; i <= 20; i++) ptr[i] = false;
	}

	void cal(const string s, int n) {
		if (s == "add") add(n);
		else if (s == "remove") remove(n);
		else if (s == "check") check(n);
		else if (s == "toggle") toggle(n);
		else cout << "retry!" << '\n';
	}	
	void cal(const string s) {
		if (s == "all") all();
		else if (s == "empty") empty();
		else cout << "retry!" << '\n';
	}

};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Set ptr = new bool[21];
	
	int m;
	cin >> m;
	
	while (m--) {
		string s; int n;
		
		
		cin >> s;

		if (s == "all" || s == "empty") {
			ptr.cal(s);
		}
		else {
			cin >> n;
			ptr.cal(s, n);
		}
	}

}


// 2. bitMask
#include <iostream>
#include <string>
using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m;
	int bit = 0, num = 0;
	string input;

	cin >> m;
	while (m--) {
		
		input.clear();
		cin >> input;
		
		if(input == "add"){
			cin >> num;
			bit |= (1 << num);
		}
		else if(input == "remove"){
			cin >> num;
			bit &= ~(1 << num);
		}
		else if(input == "check"){
			cin >> num;
			if (bit & (1 << num)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (input == "toggle") {
			cin >> num;
			bit ^= (1 << num);
		}
		else if(input == "all"){
			bit = (1 << 21) - 1;
		}
		else if(input == "empty"){
			bit = 0;
		}
	}

}

