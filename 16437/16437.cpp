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
	int bridge;
	long long int cnt;
};

list<land> isLand[123457];

long long int cntWolf(int idx = 1, long long int wolf = 0) {
	
	list<land>::iterator i;
	for (i = isLand[idx].begin(); i != isLand[idx].end(); i++) {
		if (!(i->bridge)) continue; // 1�� ��

		// Logic
		if (i->isSheep) {
			if (i->cnt >= wolf) {
				i->cnt -= wolf;
				wolf = 0;
			}
			else {
				i->cnt = 0;
				wolf -= i->cnt;
			}
			long long int tmp = cntWolf(i->number, wolf);
			wolf = wolf < tmp ? wolf : tmp;

		}
		else {
			long long int tmp = cntWolf(i->number, wolf + i->cnt);
			wolf = wolf < tmp ? wolf : tmp;
		}

		
	}
	return wolf;
}

int main() {

	// input
	isLand[1].push_back({ 1, true, 0, 0 });
	
	cin >> n;
	for (int i = 2; i <= n; i++) {
		land tland;

		char tmp; cin >> tmp;
		tland.number = i;
		tland.isSheep = (tmp == 'S' ? true : false);
		cin >> tland.cnt;
		cin >> tland.bridge;

		isLand[tland.bridge].push_back(tland);
	}

	// solve
	cntWolf();

	long long int alivesheep(0);

	for (int i = 1; i <= n; i++) {
		for (auto j : isLand[i]) {
			if (j.isSheep) alivesheep += j.cnt;
		}
	}

	// output
	cout << alivesheep;
}

//cout << "IDX: " << j.number << " cnt:" << j.cnt << " totalWolf:" << j.totalWolf << endl;