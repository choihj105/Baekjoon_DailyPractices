// kmp �˰���, Rabin-karp
#include <iostream>
#include <functional>
#include <string>
using namespace std;

int main() {
	string s, k, str;
	cin >> s >> k;
	
	hash<string> str_hash;
	int ans = str_hash(k);

	// ���ڸ� �� ���ڿ� str
	for (int i = 0; i < k.size(); i++) str += s[i];
	
	// s�� �� �ε�������, �ؽ��� �̿��Ͽ� ���Ե��� ���ϱ�
	bool flag = false;
	for (int i = 0; i < str.size() - k.size() + 1; i++) {

		if (ans == str_hash(str.substr(i, k.size()))) {
			
			flag = true;
			// �ؽ����� �ߺ��� ��� �� �� �� üũ
			for (int j = 0; j < k.size(); j++) {
				if (str[i + j] != k[j]) {
					flag = false;
					break;
				}
			}
			break;
		}
	}

	cout << flag;
}


//int main() {
//	string a, b, n;
//	cin >> a >> b;
//
//	for (auto it : a) {
//		if (it - '0' < 0 || it - '0' > 9) n += it;
//	}
//
//	if (n.find(b) == n.npos) cout << 0;
//	else cout << 1;
//}