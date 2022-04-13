#include <iostream>
using namespace std;

int arr[80];
int n;

bool isSame(int diff, int end) {

	string a;
	for (int i = 0; i < end; i++) {
		a.push_back(arr[i]);
	}

	for (int i = 0; i + diff * 2 <= end; i++) {
		if (a.substr(i, diff) == a.substr(i + diff, diff)) return true;
	}

	return false;
}

bool check(int cnt) {
	
	int end = cnt + 1;

	// 1 ~ cnt/2 숫자 확인
	for (int i = 1; i <= end/ 2; i++) {
		
		if (isSame(i, end)) return false;
	}
	return true;
}


void DFS(int cnt) {
	
	if (cnt == n) {
		for (int i = 0; i < n; i++) {
			cout << arr[i];
		}
		exit(0);
	}

	for (int i = 1; i < 4; i++) {

		// 1, 2, 3 넣기
		arr[cnt] = i;

		// check() 함수
		if (check(cnt)) DFS(cnt + 1); 
	}


}


int main() {

	cin >> n;
	DFS(0);

}