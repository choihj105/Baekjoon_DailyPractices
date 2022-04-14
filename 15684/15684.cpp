// BFS ����Ž��

#include <iostream>
using namespace std;

// (n-1)*h
int n, m, h; // n ������, m ���� �ִ� ������, h: ������  

// ��ġ�� ������ ����: 1 ���� :1
bool arr[11][31] = {false,}; // (���� n,  ����, h)
//
//void check() {
//	for (int col = 1; col <= h; col++) {
//		for (int row = 1; row <= n; row++) {
//			cout << arr[row][col] << " ";
//		}
//		cout << "\n";
//	}
//	cout << '\n';
//}

bool Play() {

	for (int row = 1; row <= n; row++)
	{
		int tmp = row;
		for (int col = 1; col <= h; col++) {

			if (arr[tmp][col]) {
				tmp++;  
			}
			else if (arr[tmp-1][col]) {
				tmp--;
			}
		}

		//cout << row << " : " << tmp << endl;
		if (tmp != row) return false;
		
	}
	return true;
}

void BFS(int cnt, int t, int x = 0, int y = 0) {

	if (cnt == t) {
		if (Play()) {
		cout << t << endl;
		exit(0);
		}
		
		return;
		
	}

	else {
		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= h; j++) {

				if (!arr[i][j] && !arr[i+1][j]) {
					arr[i][j] = true;
					BFS(cnt + 1, t);
					arr[i][j] = false;
					
				}
			}
		}
	}
	
}

int main() {
	cin >> n >> m >> h;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		arr[b][a] = true;
	}


	BFS(0, 1); BFS(0, 1); BFS(0, 2); BFS(0, 3);
	cout << -1;
	
	
}