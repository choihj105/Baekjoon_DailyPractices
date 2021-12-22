// 2798. 블랙잭
// 카드 합이 21 넘지 않는 한도 내에서, 카드 합을 최대한 크게 만드는 게임
// 이번 규칙에선 N개의 카드에서 3개를 선택 후 M을 넘지 않으면서 M과 최대한 가깝게 만드는 게임
// 입력 : 3 <= N <= 100. 10 <= M <= 300,000, 0 < 카드 숫자 < 100,000 양의 정수

// 조합문제를 푸는것, 즉 N C 3을 하여 M의 값에 맞춘다. 최대 값 100C3이여도 100*99*98/6이기 때문에 일일히 구하도록한다
#include <iostream>

int A[100];
int basket[3];
bool check[100];
int result = 0;

// 1. 재귀적 방법으로 조합 구현하기.
void DFS(int idx, int cnt) {
	if (cnt == 3) { result = basket[0] + basket[1] + basket[2];  return; } // cal()에 해당하는 함수

	for (int i = idx; i < 3; i++) {
		if (check[i]) { continue; }

		check[i] = true;
		//basket[cnt] = 




	}



}

int main() {
	

	
	int n;
	int Max_m;
	

}