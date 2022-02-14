// # 10972
/*

i: 1 <= N <= 10,000 , int [N] ����

o: ���� ���� , ���� �������̶�� -1 ���

sol)

1. ���� ����� �Լ��� ���� �ڿ������� �� ���� ���ڸ� ���� O(N! *N)

2. �ٸ� ����� ����� ����
������ �����Ǵ� ����� ��������.


*/

#include <iostream>
#define MAX 10000
using namespace std;

void Input(int Arr[], int N) {
	for (int i = 0; i < N; i++) {
		cin >> Arr[i];
	}
}

bool next_Permutaion(int Arr[], int N) {

	int i = N - 1;
	
	// �ڿ��� ���� ���� �ϴ� ���� ã�� // ��������
	while (i > 0 && Arr[i - 1] > Arr[i]) {
		i--;
	}

	if (i == 0) return false;


	int j = N - 1;
	// i��° �� �ٷ� ���� ������ ū �� ã��
	while (Arr[i -1] > Arr[j]) {
		--j;
	}

	swap(Arr[i - 1], Arr[j]);

	
	// i ��° ������ ���������� ��� ������
	for (int k = i, h = N - 1; k < h; k++, h--) {
		swap(Arr[k], Arr[h]);
	}

	return true;
}

int main() {

	int Arr[MAX];
	int N;
	cin >> N;

	Input(Arr, N);

	if (next_Permutaion(Arr, N)) {
		
		for (int i = 0; i < N; i++) {
			cout << Arr[i] << ' ';
		}
		
	}

	else {
		cout << -1;
	}


}























































//
//int G_n;
//int G_arr[MAX];
//int G_result[MAX];
//
//bool G_visited[MAX] = { false, };
//bool G_next = false;
//
//void Input(int n) {
//	for (int i = 0; i < n; i++) {
//		cin >> G_arr[i];
//	}
//}
//
//void DFS(int cnt = 0) {
//
//	if (cnt == G_n) {
//
//		if (G_next) {
//
//			for (int i = 0; i < G_n; i++) {
//				cout << G_result[i] << ' ';
//			}
//			exit(0);
//		}
//
//		G_next = true;
//		return;
//	}
//
//	for (int i = G_arr[cnt]; i <= G_n; i++) {
//
//		if (G_visited[i -1]) continue;
//
//		G_result[cnt] = i;
//		G_visited[i - 1] = true;
//		DFS(cnt + 1);
//		G_visited[i - 1] = false;
//
//	}
//}
//
//int main() {
//
//	cin >> G_n;
//	Input(G_n);
//	DFS();	
//
//}
//
//











/* try 1 , �ð��ʰ� ����
* 

int G_arrA[MAX];
int G_arrB[MAX];

bool G_visited[MAX] = {false,};
bool G_isEnd = false;

void Input(int n) {
	for (int i = 0; i < n; i++) {
		cin >> G_arrB[i];
	}


}

bool Check() {

	for (int i = 0; i < G_n; i++) {
		if (G_arrA[i] != G_arrB[i]) return false;
	}
	return true;
}

void DFS(int cnt = 0) {

	if (cnt == G_n) {

		if (G_isEnd) {
			for (int i = 0; i < G_n; i++) {
				cout << G_arrA[i] << " ";
			}
			exit(0);

		}
		if (Check()) G_isEnd = true;
		return;
	}


	for (int i = 0; i < G_n; i++) {

		if (!G_visited[i]) {
			G_visited[i] = true;
			G_arrA[cnt] = i+1;

			DFS(cnt + 1);
			G_visited[i] = false;
		}

	}

}
*/