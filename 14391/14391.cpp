// #14391
/*

i: 1 <= N, M<= 4 N열, M행, 

o:

sol)
1. 행 and 열로 쪼갠 수?

*/
#include <iostream>
#include <cmath>
using namespace std;


int main() {

	int N, M;
	cin >> N >> M;
	int arr[4][4] = { 0, };

	int* row = new int[N];
	
	// input
	int row_total = 0;
	for (int i = 0; i < N; i++) {
		cin >> row[i];
		row_total += row[i];
	}

	for (int i = 0; i < N; i++) {
		arr[i][0] = row[i] / 1000;
		arr[i][1] = (row[i] % 1000) / 100;
		arr[i][2] = (row[i] % 100) / 10;
		arr[i][3] = (row[i] % 10) / 1;
	}

	int column[4] = { 0, };
	
	// row to coiumn;
	for (int i = 0; i < 4; i++) {
		
		for (int j = 0; j < N; j++) {
			column[i] += arr[j][i] * pow(10, N-j-1); 
		}
		
	}

	// total 구하기
	int column_total = 0;
	for (int i = 0; i < 4; i++) {
		column_total += column[i];
	}

	// Output
	if (row_total > column_total) {
		cout << row_total;
	}
	else {
		cout << column_total;
	}

}