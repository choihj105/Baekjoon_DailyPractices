// 1�� ������ ������
// 2�� ~ n���� ���� t = W(����), S(��)  a = ����  p = ������ �� �� �ִ� �ٸ�

// Ʈ���� ������ָ� ���� ������

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
		if (!(i->bridge)) continue; // 1�� ��
		
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