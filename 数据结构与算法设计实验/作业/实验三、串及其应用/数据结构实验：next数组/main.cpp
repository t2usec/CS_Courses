#include <bits/stdc++.h>

using namespace std;

vector<int> gen_next(string s) {
	int len = s.size();
	vector<int> next(len, 0);
	int j = 0;
	for (int i = 1; i < len; ++i) {
		while (j > 0 && s[i] != s[j]) {
			j = next[j - 1];
		}
		if (s[i] == s[j]) {
			next[i] = ++j;
		}
	}
	return next;
}

vector<int> gen_next2(string s) {
	vector<int> next = gen_next(s);
	vector<int> next2;
	next2.push_back(-1);
	for (int i = 0; i < next.size()-1; i++) {
		next2.push_back(next[i]);
	}
	return next2;
}

vector<int> gen_next3(string s) {
	vector<int> next2 = gen_next2(s);
	vector<int> next3;
	for (int i = 0; i < next2.size(); i++){
		next3.push_back(next2[i]+1);
	}
	return next3;
}

int main() {
	string s;
	cin >> s;
	vector<int> next = gen_next3(s); // 这里修改 gen_next() 为 gen_next2() 或 gen_next3() 即可，分别代表第一题第二题和第三题
	for (int i = 0; i < next.size(); ++i) {
		cout << next[i] << (i < next.size() - 1 ? " " : "");
	}
	cout << endl;
	return 0;
}