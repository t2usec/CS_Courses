#include <bits/stdc++.h>

using namespace std;

int main() {
	queue<int> q1,q2;
	int n;
	cin >> n;
	while(n--) {
		int m;
		cin >> m;
		if (m%2) {
			q1.push(m);
		} else {
			q2.push(m);
		};
	}
	while (!q1.empty()) {
		int cnt=2,i=0;
		while (cnt--&&!q1.empty()) {
			if (i++) {
				cout << " ";
			}
			cout << q1.front();
			q1.pop();
		}
		if (!q2.empty()) {
			cout << " " << q2.front() << " ";
			q2.pop();
		}
	}
	int i=0;
	while (!q2.empty()) {
		if (i++) {
			cout << " ";
		}
		cout << q2.front();
		q2.pop();
	}
	return 0;
} 

