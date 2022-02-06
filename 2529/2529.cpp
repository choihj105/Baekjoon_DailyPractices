// #2529
/*

i:  부등호 n개
o:  MAX, MIN 의 조건식을 만족하는 숫자

*/

#include <iostream>
using namespace std;

#define endl '\n'
#define MAX 10

int G_n;
int G_select[MAX];

int G_MAX[MAX];
int G_MIN[MAX];
bool isCheck = false;

char G_operators[MAX];
bool G_visited[MAX] = {false, };

void Input(int n) {
	for (int i = 0; i < n; i++) {
		cin >> G_operators[i];
	}
}


bool Check(int idx) {

	if (idx < 0) return true;

	if (G_operators[idx] == '>') { 
		if (G_select[idx] > G_select[idx + 1]) return true;
		else return false;
	}
	
	if (G_operators[idx] == '<') { 
		if (G_select[idx] < G_select[idx + 1]) return true;
		else return false;
	}

	return false;
}

void DFS(int cnt = 0) {

	if (cnt == (G_n + 1)) {
		
		if (!isCheck) {
			for (int i = 0; i < (G_n + 1); i++) G_MAX[i] = G_select[i];
		}
		
		isCheck = true;
		
		if (isCheck) {
			for (int i = 0; i < (G_n + 1); i++) G_MIN[i] = G_select[i];
		}

		return;
	}

	for (int i = 9; i >= 0; i--) {
		if (!G_visited[i]) {
		
			G_visited[i] = true;
			G_select[cnt] = i;
			
			if (Check(cnt-1)) DFS(cnt + 1);
			G_visited[i] = false;
		}
	}
}

int main() {
	
	cin >> G_n;
	Input(G_n);
	DFS();

	for (int i = 0; i < (G_n + 1); i++) {
		cout << G_MAX[i];
	}
	cout << endl;

	for (int i = 0; i < (G_n + 1); i++) {
		cout << G_MIN[i];
	}
	

}