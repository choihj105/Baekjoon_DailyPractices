#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b, c, t = 0;
	while (cin >> a >> b >> c && (a || b || c)) {
		cout << "Triangle " << '#' << ++t << '\n';

		float t; char i;
		if (a == -1) {
			i = 'a';
			t = (c * c) - (b * b); 
		}
		else if (b == -1){
			i = 'b';
			t = (c * c) - (a * a); 
		}
		else {
			i = 'c';
			t = (a * a) + (b * b);
		}
		
		t = sqrt(t);
		cout << fixed;
		cout.precision(3);
		if(t > 0)
			cout << i << " = " << t << '\n';
		else {
			cout << "Impossible."<< '\n';
		}
		cout << '\n';
	}
}