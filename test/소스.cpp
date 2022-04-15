#include <iostream>
using namespace std;

int main() {


	int n = 3;
	int h = 4;



	for (int i = 0; i < (n - 1) * h; i++) {

		int x = i % (n -1);
		int y = i % h;

		cout << x << " " << y << endl;
	}
}

/*

1 1
2 1
1 2
2 2
1 3
2 3
1 4
2 4 

*/