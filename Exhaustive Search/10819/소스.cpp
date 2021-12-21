/*  백준 10819 "차이를 최대로"
	
	N개의 정수로 이루어진 배열 A가 주어진다.이때, 배열에 들어있는 정수의 순서를 적절히 바꿔서 
	다음 식의 최댓값을 구하는 프로그램을 작성하시오. 

	|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]| 의 MAX값
*/

// 1. 전략: 완전탐색 .. n값은 3 <= N <= 8 조건이기에 무작정 찾는 모든 후보검색을 쓰기로 함
// DFS 깊이우선탐색, Back Tracking .. 


#include <iostream>
using namespace std;

int A[10]; // 주어진 배열
int n; // 정수 개수
int basket[10]; // 차례대로 배열을 담을 통
bool basket_check[10]; // 통에 배열이 잠겨있는지 확인하는 용도
int MAX_result = 0; // 최대 값

int cal() {
	int result = 0;
	for (int i = 0; i < n - 1; i++) {
		result += abs(basket[i] - basket[i + 1]);
	}
	return result;
}

// 1. 재귀적 방법
void DFS(int cnt) { 
	if (cnt == n) {
		MAX_result = max(MAX_result, cal()); return;
	}

	for (int i = 0; i < n; i++) {

		if (basket_check[i]) continue;

		basket[cnt] = A[i];
		basket_check[i] = true;
		DFS(cnt + 1);
		basket_check[i] = false;
	}
}
// 겹치지않은 순열 순서대로 basket에 집어넣어보면서 값을 나오게 하는 알고리즘이다.

int main() {

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	DFS(0);

	cout << MAX_result;
	
}



































//int arr[10];
//int check[10];
//int use_arr[10];
//int n;
//int max_n = 0;
//
//// 완성된 배열의 값을 알기위한 계산함수
//int cal() {
//	int result = 0;
//
//	for (int i = 0; i < n-1; i++) {
//		result += abs(use_arr[i] - use_arr[i + 1]);
//	}
//	return result;
//}
//
//// 1. 재귀 함수로 구현하기
//void dfs(int cnt) {
//	if (cnt == n) { max_n = max(max_n, cal()); return; }
//
//	for (int i = 0; i < n; i++) {
//		if (check[i]) continue;
//
//		use_arr[cnt] = arr[i];
//		check[i] = 1;
//		dfs(cnt + 1);
//		check[i] = 0;
//	}
//}
//
//int main() 
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
//
//	for (int i = 0; i < n; i++) {
//		check[i] = 1;
//		use_arr[0] = arr[i];
//		dfs(1);
//		check[i] = 0;
//	}
//
//	cout << max_n;
//
//}