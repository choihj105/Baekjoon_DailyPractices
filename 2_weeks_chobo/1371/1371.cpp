#include <iostream>
#include <string>
using namespace std;

int main() {
	
	int alpha[26] = { 0, };

	while (true) {
		char c = 0;
		cin >> c;
		if (c == 0) break;
		if ('a' <= c && c <= 'z') alpha[c - 'a']++;
	}

	int bigest = 0;
	for (int i = 0; i < 26; i++) {
		if (bigest < alpha[i]) bigest = alpha[i];
	}

	for (int i = 0; i < 26; i++) {
		if (alpha[i] == bigest) cout << char('a'+ i);
	}

}



// 정답이 되진 않았다
//string alpabet = "abcdefghijklmnopqrstuwvxyz";
//int idx[26] = { 0, };

//string str, tmp;
//while(getline(cin, tmp)){
//	str += tmp;
//}

//cout << str;

//for (auto it = str.begin(); it != str.end(); it++) {
//	if (*it != ' ') {
//		int num = alpabet.find(*it);
//		++(idx[num]);
//	}
//}

//int bigest = 0;
//for (int i = 0; i < 26; i++) {
//	if (bigest < idx[i]) bigest = idx[i];
//}

//for (int i = 0; i < 26; i++) {
//	if (idx[i] == bigest) cout << alpabet.at(i);
//}
//
