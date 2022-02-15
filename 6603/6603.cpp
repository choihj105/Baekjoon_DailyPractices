// #6603
/*

i: 6 < k < 13, 여러가지의 테스트 케이스

o: 조합식

sol)
조합


*/

#include <iostream>
#define MAX 13
using namespace std;

int Arr[MAX];

int G_Nrr[MAX];
bool G_Visitied[MAX] = {false,};
int G_N;


void Input(int N) {
	for (int i = 0; i < N; i++) {
		cin >> Arr[i];
	}
}

void Reset() {
	
	for (int i = 0; i < MAX; i++) {
		G_Visitied[i] = false;
		G_Nrr[i] = 0;
	}
}


void DFS(int N = 0, int cnt = 0) {

	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			int tmp = G_Nrr[i];
			cout << Arr[tmp] << ' ';
		}
		cout << '\n';
	}

	for (int i = N; i < G_N; i++) {

		if (!G_Visitied[i]) {

			G_Nrr[cnt] = i;
			G_Visitied[i] = true;
			DFS(i + 1, cnt + 1);
			G_Visitied[i] = false;
		}
	}
}


int main() {
	
	while (cin >> G_N) {
		Input(G_N);
		DFS();
		Reset();
		cout << '\n';

		if (G_N == 0) break;
	}

	

}