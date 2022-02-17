// #14391
/*

i: 1 <= N, M<= 4 N열, M행, 

o:

sol)



1. 행 and 열로 쪼갠 수?
*/
//
//#include <iostream>
//using namespace std;
//
//
//
//int main() {
//
//}
//



// 1. try 무작정 트라이
//#include <iostream>
//#include <cmath>
//using namespace std;
//
//
//int main() {
//
//	int n, m;
//	cin >> n >> m;
//	int arr[4][4] = { 0, };
//
//	int* row = new int[n];
//	
//	// input
//	int row_total = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> row[i];
//		row_total += row[i];
//	}
//
//	for (int i = 0; i < n; i++) {
//		arr[i][0] = row[i] / 1000;
//		arr[i][1] = (row[i] % 1000) / 100;
//		arr[i][2] = (row[i] % 100) / 10;
//		arr[i][3] = (row[i] % 10) / 1;
//	}
//
//	int column[4] = { 0, };
//	
//	// row to coiumn;
//	for (int i = 0; i < 4; i++) {
//		
//		for (int j = 0; j < n; j++) {
//			column[i] += arr[j][i] * pow(10, n-j-1); 
//		}
//		
//	}
//
//	// total 구하기
//	int column_total = 0;
//	for (int i = 0; i < 4; i++) {
//		column_total += column[i];
//	}
//
//	// output
//	if (row_total > column_total) {
//		cout << row_total;
//	}
//	else {
//		cout << column_total;
//	}

//}




// 2. 4x4이므로 모든 경우 다 구하기 -> 조합으로 구하기

#include <iostream>
#include <string>
using namespace std;

int Num[4][4]; // -1 -> 접근 불가
int Marked[4][4]; // -1: 접근 불가 0 : 세로, 1 : 가로
bool Check[16] = { false , }; // nCm을 선택  ex) 3x2 면 6까지만 사용
int N, M;
int K; // N * M 
int Res = -1; // 최대값 구하기,, 
	
void Input() {

	fill(&Num[0][0], &Num[3][4], -1); // 모두 -1로
	fill(&Marked[0][0], &Marked[3][4], -1); // 모두 -1로

	cin >> N >> M;
	K = N * M;

	for (int i = 0; i < N; i++)
	{
		string Inp; cin >> Inp;
		for (int j = 0; j < Inp.length(); j++)
		{
			Num[i][j] = Inp[j] - '0';
		}
	}
}

void Marked_reset() {
	fill(&Marked[0][0], &Marked[3][4], -1);
}

void Marking() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Marked[i][j] = Check[(j + M * i)];
		}
	}
}

// row : true, column : false
int isNext(int n, int m, bool row_column) {
	int tmp = 10;
	if (row_column) {

		if (m == 3) return 1;

		if (Marked[n][m + 1] == 1) {
			return tmp * isNext(n, m + 1, row_column);
		}
		else {
			return 1;
		}

	}
	else {
		
		if (n == 3) return 1;

		if (Marked[n + 1][m] == 0) {
			return tmp * isNext(n + 1, m, row_column);
		}
		else {
			return 1;
		}
	}



}

// 가로 세로 별로 값 구하기
int Solve() {

	int row = 0;
	int column = 0;
	
	// 값 구하기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
			// 가로
			if (Marked[i][j] == 1) {
				row += Num[i][j] * isNext(i, j, true);
			}

			// 세로
			else if (Marked[i][j] == 0) {
				column += Num[i][j] * isNext(i, j, false);
			}
		}
	}

	return row + column;
}

void DFS(int dest, int cnt = 0, int n = 0) {
	if (cnt == dest) {
		int total;
		
		Marking();
		total = Solve();
		Marked_reset();

		if (Res < total) {	Res = total;}
		
		return;
	}

	for (int i = n; i < K; i++) {
		if (!Check[i]) {
			Check[i] = true;
			DFS(dest, cnt + 1, i + 1);
			Check[i] = false;
		}
	}
}




int main() {
	Input();

	for (int i = 0; i <= K; i++) {
		DFS(i);
	}

	cout << Res;

}