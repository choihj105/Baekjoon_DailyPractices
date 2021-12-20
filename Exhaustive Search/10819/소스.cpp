/*  백준 10819 "차이를 최대로"
	
	N개의 정수로 이루어진 배열 A가 주어진다.이때, 배열에 들어있는 정수의 순서를 적절히 바꿔서 
	다음 식의 최댓값을 구하는 프로그램을 작성하시오. 

	|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]| 의 MAX값
*/

// 1. 전략: 완전탐색 .. n값은 3 <= N <= 8 조건이기에 무작정 찾는 모든 후보검색을 쓰기로 함
// 모든 후보검색 O(2**n)
// DFS 깊이우선탐색, Back Tracking .. 

#include <iostream>
#include <vector>
using namespace std;

int arr[10];
int check[10];
int use_arr[10];
int n;
int max_n = 0;

int cal() {
	int result = 0;

	for (int i = 0; i < n-1; i++) {
		result += abs(use_arr[i] - use_arr[i + 1]);
	}
	return result;
}

void dfs(int cnt) {
	if (cnt == n) { max_n = max(max_n, cal()); return; }

	for (int i = 0; i < n; i++) {
		if (check[i]) continue;

		use_arr[cnt] = arr[i];
		check[i] = 1;
		dfs(cnt + 1);
		check[i] = 0;
	}
}

int main() 
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		check[i] = 1;
		use_arr[0] = arr[i];
		dfs(1);
		check[i] = 0;
	}

	cout << max_n;

}