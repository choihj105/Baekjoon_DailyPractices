// #15650
/*

Problem : 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

i : 1<= M <= N <= 8

o : n C m




sol) 조합을 구하는 문제


// 핵심 문제법은 첫번째 원소가 두번째 원소보다 작아야함
*/

#include <iostream>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX] = { 0, };
bool visited[MAX] = { 0, };

void dfs(int num = 1, int cnt = 0) {
	
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;

	} // 정답일때

	for (int i = num; i <= n; i++) {

		if (!visited[i]) {
			visited[i] = true;
			arr[cnt] = i;
			dfs(i + 1, cnt + 1);
			visited[i] = false;
		}

	}
}

int main() {

	cin >> n >> m;
	dfs(1, 0);

}
