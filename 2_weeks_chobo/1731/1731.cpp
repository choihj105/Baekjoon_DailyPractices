#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int a, b, c;
	cin >> a >> b >> c;

	int tmp = c;
	while (N-- -3) { cin >> tmp;}

	tmp = ((b - a) == (c - b)) ? tmp + (b - a) : tmp * (b / a);

	cout << tmp;
}