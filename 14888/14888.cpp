#include <iostream>
using namespace std;

/* more short coding, second way */
int add, sub, mul, Div;
int nArr[11], n, MAX = -1000000000, MIN = 1000000000;

void DFS(int cnt, int result) {
	if (cnt == n) {
		MAX = MAX < result ? result : MAX;
		MIN = MIN > result ? result : MIN;
	}
	else {
		if(add) {
			add--;
			DFS(cnt + 1, result + nArr[cnt]);
			add++;
		}
		if(sub) {
			sub--;
			DFS(cnt + 1, result - nArr[cnt]);
			sub++;
		}
		if(mul) {
			mul--;
			DFS(cnt + 1, result * nArr[cnt]);
			mul++;
		}
		if(Div) {
			Div--;
			DFS(cnt + 1, result / nArr[cnt]);
			Div++;
		}
	}
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> nArr[i];
	cin >> add >> sub >> mul >> Div;
	DFS(1, nArr[0]);

	cout << MAX << '\n' << MIN;
}



/*first Way*/

//int nArr[11]; // min : 2 ~ max : 11
//int oArr[10]; // min : 0 ~ max : 3
//int oper[4]; // operator 0: ADD, 1: SUB , 2: MUL, 3: DIV
//
//int oArrDfs[10];
//bool isVisited[10];
//
//int n;
//int MIN = 1000000000; // default 10¾ï
//int MAX = -1000000000;
//
//// Input
//void Input(int n) {
//	for (int i = 0; i < n; i++) cin >> nArr[i];
//	for (int i = 0; i < 4; i++) cin >> oper[i];
//
//	int idx =0;
//	for (int i = 0; i < 4; i++) {
//		
//		for (int j = 0; j < oper[i]; j++) oArr[idx + j] = i;
//		idx += oper[i];
//	}
//	
//}
//
//// calculate
//int Cal() {
//	int tmp = 0;
//	int k = nArr[0];
//
//	while (tmp < (n-1)) {
//		switch (oArrDfs[tmp])
//		{
//		case 0:
//			k += nArr[tmp + 1];
//			break;
//		case 1:
//			k -= nArr[tmp + 1];
//			break;
//		case 2:
//			k *= nArr[tmp + 1];
//			break;
//		case 3:
//			k /= nArr[tmp + 1];
//			break;
//		}
//		++tmp;
//	}
//	return k;
//}
//
//void DFS(int cnt) {
//	if (cnt == (n - 1)) {
//		// cal ÈÄ, ÃÖ´ñ°ª ÃÖ¼Ú°ª ºñ±³
//		int tmp = Cal();
//		MAX = MAX < tmp ? tmp : MAX;
//		MIN = MIN > tmp ? tmp : MIN;
//
//		return;
//	}
//
//	for (int i = 0; i < (n - 1); i++) {
//
//		if (!isVisited[i]) {
//			isVisited[i] = true;
//			oArrDfs[cnt] = oArr[i];
//			DFS(cnt + 1);
//			isVisited[i] = false;
//		}
//	}
//}
//
//
//int main() {
//	cin >> n;
//	Input(n);
//	DFS(0);
//
//	cout << MAX << endl;
//	cout << MIN << endl;
//}


// DFS - permutation