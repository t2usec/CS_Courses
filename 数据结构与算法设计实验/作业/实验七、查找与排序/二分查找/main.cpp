#include <bits/stdc++.h>

using namespace std;

void binary_search(int x, vector<int>& a) {
	int i=0;
	int j=a.size()-1;
	int s=-1;
	while(i<=j){
		int n = (i+j)/2;
		if (a[n] >= x) {
			j = n - 1;
			if (a[n] == x) {
				s = n + 1;
			}
		} else if (a[n] < x) {
			i = n + 1;
		}
	}
	if (s != -1) {
		cout << s << endl;
		return;
	}
	cout << "None" << endl;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	for (int i=0; i<m; i++) {
		int x;
		cin >> x;
		binary_search(x, a);
	}
}