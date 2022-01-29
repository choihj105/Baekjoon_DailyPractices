// #18290 NM과 K(1)

/*

i:  1 <= N, M <= 10  , 1 <= K <= Min(4, N*M)
o:  k개의 최대값

sol)

차례대로 풀어가면서 백트래킹


*/

#include <iostream>
using namespace std;

#define MAX 10

int arr[100] = {0, };

int grid[MAX][MAX];
bool visited[MAX][MAX] = { 0, };
bool adjacent[MAX][MAX] = { 0, };

int n, m, k;
int result = 0;


void switchAdjacent(int n_ , int m_, bool toggle) {

	if (toggle) {
		if (n_ > 0) adjacent[n_ - 1][m_] = true;
		if (n_ < n-1) adjacent[n_ + 1][m_] = true;
		if (m_ > 0) adjacent[n_][m_ - 1] = true;
		if (m_ < m- 1) adjacent[n_][m_ + 1] = true;
		
	}
	else {
		if (n_ > 0) adjacent[n_ - 1][m_] = false;
		if (n_ < n - 1) adjacent[n_ + 1][m_] = false;
		if (m_ > 0) adjacent[n_][m_ - 1] = false;
		if (m_ < m - 1) adjacent[n_][m_ + 1] = false;

	}
	
}



void dfs(int cnt = 0) {
	int tmp = 0;

	if (cnt == k) {

		for (int i = 0; i < k; i++) tmp += arr[i];
		if (tmp > result) { result = tmp; }
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (!visited[i][j] && (!adjacent[i][j]))
				visited[i][j] = true;
				
				switchAdjacent(i, j, true);
				arr[cnt] = grid[i][j];
				dfs(cnt + 1);
				
				visited[i][j] = false;
				switchAdjacent(i, j, false);
		}
	}


}



int main() {

	cin >> n >> m >> k;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	dfs();
	
	cout << result;
	


	


	
}