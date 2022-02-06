// #1248
/*


 A[N]
 S[N] , i <= j

i: N <= 10, 부호들에 대한 배열
o: 수열의 원소 N개를 출력



sol)


*/

#include <iostream>
using namespace std;

#define MAX 10
#define endl '\n'

int G_n;
int G_select[MAX];
char G_operators[MAX][MAX];

void Input(int n) {
	
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			cin >> G_operators[i][j];
		}
	}
}

bool Check(int idx) {

	int Sum = 0;
	for (int i = idx; i >= 0; i--) {

		Sum += G_select[i];

		if (G_operators[i][idx] == '+' && Sum <= 0) return false;
		if (G_operators[i][idx] == '-' && Sum >= 0) return false;
		if (G_operators[i][idx] == '0' && Sum != 0) return false;

	}
	
	return true;
}



void DFS(int cnt = 0 ) {
	
	if (cnt == G_n) {
		for (int i = 0; i < G_n; i++) {
			cout << G_select[i] << " ";
		}
		cout << endl;
		exit(0);
	}

	for (int i = -10; i <= 10; i++) {
		G_select[cnt] = i;
		if (Check(cnt) == true) DFS(cnt + 1);
	}

}



int main() {

	cin >> G_n;
	Input(G_n);
	DFS();
			
}

