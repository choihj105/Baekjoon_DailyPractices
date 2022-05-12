// 1번 섬으로 가야함
// 2번 ~ n번섬 까지 t = W(늑대), S(양)  a = 갯수  p = 섬으로 갈 수 있는 다리

// 트리를 만들어주면 좋지 않을까

#include <iostream>
#include <list>
using namespace std;

int n; // 2 ~ 123456
struct land {
	int number;
	bool isSheep;
	long long int cnt;
	int bridge;
	long long int totalWolf;
};

list<land> isLand[123457];

void cntWolf(int idx = 1, int wolf = 0) {
	
	list<land>::iterator i;
	for (i = isLand[idx].begin(); i != isLand[idx].end(); i++) {
		if (!(i->bridge)) continue; // 1번 섬
		
		if (i->isSheep) {
			i->totalWolf = wolf;
			cntWolf(i->number, wolf);
		}
		else {
			i->totalWolf = wolf + i->cnt; 
			cntWolf(i->number, wolf + i->cnt);
		}
	}
}

int main() {

	// input
	isLand[1].push_back({ 1, true, 0, 0, 0 });
	
	cin >> n;
	for (int i = 2; i <= n; i++) {
		land tland;

		char tmp; cin >> tmp;
		tland.number = i;
		tland.isSheep = (tmp == 'S' ? true : false);
		tland.totalWolf = 0;
		cin >> tland.cnt;
		cin >> tland.bridge;

		isLand[tland.bridge].push_back(tland);
	}

	// solve
	cntWolf();

	int alivesheep(0);

	for (int i = 1; i <= n; i++) {
		for (auto j : isLand[i]) {
			if (j.isSheep && j.cnt > j.totalWolf) {
				alivesheep += (j.cnt - j.totalWolf);
			}
		}
	}

	// output
	cout << alivesheep;
}

//cout << "IDX: " << j.number << " cnt:" << j.cnt << " totalWolf:" << j.totalWolf << endl;