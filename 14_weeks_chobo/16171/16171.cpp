// kmp 알고리즘, Rabin-karp
#include <iostream>
#include <functional>
#include <string>
using namespace std;

int main() {
	string s, k, str;
	cin >> s >> k;
	
	hash<string> str_hash;
	int ans = str_hash(k);

	// 숫자를 뺀 문자열 str
	for (int i = 0; i < k.size(); i++) str += s[i];
	
	// s의 각 인덱스마다, 해쉬를 이용하여 포함된지 구하기
	bool flag = false;
	for (int i = 0; i < str.size() - k.size() + 1; i++) {

		if (ans == str_hash(str.substr(i, k.size()))) {
			
			flag = true;
			// 해쉬값이 중복일 경우 한 번 더 체크
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