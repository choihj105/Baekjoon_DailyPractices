// #15661 링크와 스타트

/*

i : 4 <= N <= 20

o :


sol)
*/

#include <iostream>
#include <cmath>
#define endl '\n'
#define MAX 20

using namespace std;

int G_power[MAX][MAX];
bool G_visited[MAX] = { false, };
int G_n;
int G_Result = 100000000;


void Input(int n = 0) {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			cin >> G_power[i][j];

		}
	}
}

int Cal() {
	int aTeam = 0;
	int bTeam = 0;

	// aTeam;
	for (int i = 0; i < G_n; i++) {
		for (int j = 0; j < G_n; j++) {
			if (G_visited[i] && G_visited[j]) {
				aTeam += G_power[i][j];
			}
		}
	}	
	// bTeam;
	for (int i = 0; i < G_n; i++) {
		for (int j = 0; j < G_n; j++) {
			if (!G_visited[i] && !G_visited[j]) {
				bTeam += G_power[i][j];
			}
		}
	}


	return (abs(aTeam - bTeam));
}

void DFS(int cnt = 0, int num = 0, int n =0) {
	
	if (cnt == num) {
		int tmp = Cal();
		if (tmp < G_Result) G_Result = tmp;
		return;
	}

	for (int i = n; i < G_n; i++) {

		if (!G_visited[i]) {
			G_visited[i] = true;
			DFS(cnt + 1, num, i+1);
			G_visited[i] = false;
		}
	}
}

void Sol() {

	for (int i = 1; i <= G_n / 2; i++) {
		DFS(0, i, 0);
		for (int i = 0; i < G_n; i++) { G_visited[i] = false; }

	}

	cout << G_Result;
}


int main() {

	cin >> G_n;
	Input(G_n);
	Sol();

}


