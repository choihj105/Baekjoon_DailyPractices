// 1번 섬으로 가야함
// 2번 ~ n번섬 까지 t = W(늑대), S(양)  a = 갯수  p = 섬으로 갈 수 있는 다리

// 트리를 만들어주면 좋지 않을까

#include <iostream>
#include <vector>
using namespace std;

char animal[123457];
long long int animalCnt[123457];
vector<long long int> tree[123457];
int n;

long long int DFS(int n) {

	long long int cnt = 0;
	for (int i = 0; i < tree[n].size(); i++) {
		cnt += DFS(tree[n][i]);
	}

	if (animal[n] == 'W') {
		cnt -= animalCnt[n];
		if (cnt < 0) return 0;
		else return cnt;
	}
	else {
		return cnt + animalCnt[n];
	}
}


int main() {

	// Input
	cin >> n;
	for (int i = 2; i <= n; i++) {
		char c; cin >> c;
		int a, b; cin >> a >> b;
		
		animal[i] = c;
		animalCnt[i] = a;
		tree[b].push_back(i);
	}
	animal[1] = 'S';
	animalCnt[1] = 0;
	
	// Solve + Output
	cout << DFS(1);
}



//#include <iostream>
//#include <list>
//using namespace std;
//
//int n; // 2 ~ 123456
//
//struct land {
//	int number;
//	bool isSheep;
//	int bridge;
//	long long int cnt;
//};
//
//list<land> isLand[123457];
//
//long long int cntWolf(int idx = 1, long long int wolf = 0) {
//	
//	list<land>::iterator i;
//	for (i = isLand[idx].begin(); i != isLand[idx].end(); i++) {
//		if (!(i->bridge)) continue; // 1번 섬
//
//		// Logic
//		if (i->isSheep) {
//			if (i->cnt >= wolf) {
//				i->cnt -= wolf;
//				wolf = 0;
//			}
//			else {
//				i->cnt = 0;
//				wolf -= i->cnt;
//			}
//			long long int tmp = cntWolf(i->number, wolf);
//			wolf = wolf < tmp ? wolf : tmp;
//
//		}
//		else {
//			long long int tmp = cntWolf(i->number, wolf + i->cnt);
//			wolf = wolf < tmp ? wolf : tmp;
//		}
//
//		
//	}
//	return wolf;
//}
//
//int main() {
//
//	// input
//	isLand[1].push_back({ 1, true, 0, 0 });
//	
//	cin >> n;
//	for (int i = 2; i <= n; i++) {
//		land tland;
//
//		char tmp; cin >> tmp;
//		tland.number = i;
//		tland.isSheep = (tmp == 'S' ? true : false);
//		cin >> tland.cnt;
//		cin >> tland.bridge;
//
//		isLand[tland.bridge].push_back(tland);
//	}
//
//	// solve
//	cntWolf();
//
//	long long int alivesheep(0);
//
//	for (int i = 1; i <= n; i++) {
//		for (auto j : isLand[i]) {
//			if (j.isSheep) alivesheep += j.cnt;
//		}
//	}
//
//	// output
//	cout << alivesheep;
//}

//cout << "IDX: " << j.number << " cnt:" << j.cnt << " totalWolf:" << j.totalWolf << endl;