#include <iostream>
using namespace std;

int main() {
	int e, f, c; // ���� �� ��, �߰��� �� ��, �� ������ �ٲٴµ� �ʿ��� ����
	cin >> e >> f >> c;

	int cnt(0); // ���� ����
	int bottle = e + f;
	
	while (bottle >= c) {
		int newSoda = bottle / c;
		cnt += newSoda;
		bottle %= c;
		bottle += newSoda;
	}
	cout << cnt;
	
}