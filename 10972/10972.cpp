// # 10972
/*

i: 1 <= N <= 10,000 , int [N] 순열

o: 다음 순열 , 만약 마지막이라면 -1 출력

sol)


*/

#include <iostream>
#define MAX 10000
using namespace std;

int G_n;
int G_arrA[MAX];
int G_arrB[MAX];

bool G_visited[MAX];
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
				G_arrA[i];
			}
			exit(0);

		}
		if (Check()) G_isEnd = true;
		return;
	}

	for (int i = 0; i < G_n; i++) {

		if (!G_visited[i]) {
			G_visited[i] = true;
			G_arrA[i] = i;
			
			DFS(cnt + 1);
			G_visited[i] = false;
		}

	}

}

int main() {
	cin >> G_n;
	Input(G_n);
	DFS();
	
	

}