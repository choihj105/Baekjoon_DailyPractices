// # 1182.
/*

i: 1<= N <= 20, |S| <= 1,000,000, N개의 정수 |x| < 100,000

o:

sol)

*/

#include <iostream>
using namespace std;


// 2, 조합으로 푼 부분수열

int G_N;
int G_S;
int G_sequence[21];
int G_Result = 0;

bool visited[21] = {false, };

void DFS(int dest, int cnt = 0, int n = 1){

	if (cnt == dest) {
		int tmp = 0;
		
		for (int i = 1; i <= G_N; i++) {
			if (visited[i]) tmp += G_sequence[i];
		}
		
		if (tmp == G_S) ++G_Result;
		return;
	}

	for (int i = n; i <= G_N; i++) {

		if (!visited[i]) {
			visited[i] = true;
			DFS(dest, cnt + 1, i + 1);
			visited[i] = false;
		}
	}
}

void Sol() {

	for (int i = 1; i <= G_N; i++) {
		DFS(i);
	}
}

int main() {
	cin >> G_N >> G_S;
	for (int i = 1; i <= G_N; i++) {
		cin >> G_sequence[i];
	}

	Sol();

	cout << G_Result;

}






















// 1. 부분수열의 의미가 붙어있는 수열인줄 알았다.
//int cal(int *arr, int n, int s, int cnt = 1) {
//	
//	if (cnt > n) return 0;
//	
//	int result = 0;
//
//	for (int i = 0; i <= n - cnt; i++) {
//		int total = 0;
//
//		for (int j = 0; j < cnt; j++) {
//			total += arr[i + j];
//		}
//
//		if (total == s) ++result;
//	}
//
//	return result += cal(arr, n, s, cnt + 1);
//}
//
//int main() {
//
//	int n;
//	int s;
//
//	cin >> n >> s;
//
//	int* arr = new int[n];
//
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//
//
//	cout << cal(arr, n, s);
//}