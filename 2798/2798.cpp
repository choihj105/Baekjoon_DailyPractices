#include <iostream>
using namespace std;

int n, m, curMax = 0;
int iArr[100];
int oArr[3];
bool isVisited[100];


void input() {
	for (int i = 0; i < n; i++) {
		cin >> iArr[i];
	}
}

void DFS(int cnt = 0, int num = 0) {
	if (cnt == 3) {


		int tmp;
		tmp = oArr[0] + oArr[1] + oArr[2];

		if (tmp > m || curMax > tmp) return;
		
		curMax = tmp;
		return;
	}

	for (int i = num; i < n; i++) {

		if (!isVisited[i]) {
			
			isVisited[i] = true;
			oArr[cnt] = iArr[i];
			DFS(cnt + 1, i + 1);
			isVisited[i] = false;
		}
	}

}

int main() 
{
	cin >> n >> m;
	input();
	DFS();

	cout << curMax;
}