// #10973 
/*
 
i: 1<= N <= 10000

o:


sol) pre_permutaion

*/


#include <iostream>
#define MAX 10000
using namespace std;


void Input(int Arr[], int N) {
	for (int i = 0; i < N; i++) {
		cin >> Arr[i];
	}
}

bool pre_permutaion(int Arr[], int N) {
	
	int i = N - 1;
	while (i > 0 && Arr[i - 1] < Arr[i]) {
		--i;
	}

	if (i == 0) return false;

	int j = N - 1;
	while (j >= i && Arr[i - 1] < Arr[j]) {
		--j;
	}

	swap(Arr[i - 1], Arr[j]);

	for (int k = i, h = N - 1; k < h; ++k, --h) {
		swap(Arr[k], Arr[h]);
	}

	return true;
}

int main() {
	int N;
	int Arr[MAX];
	cin >> N;
	
	Input(Arr, N);

	if (pre_permutaion(Arr, N)) {
		for (int i = 0; i < N; i++) {
			cout << Arr[i] << ' ';
		}
	}
	else {
		cout << -1;
	}


	

}