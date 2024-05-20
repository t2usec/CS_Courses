#include <bits/stdc++.h>

using namespace std;

int main() {
	int m, n;
	while(cin >> n >> m, m != 0, n != 0){
		vector<vector<int>> vec(n, vector<int>(n, 0));
		for (int i=0; i<m; i++) {
			int x, y;
			cin >> x >> y;
			vec[x-1][y-1] = 1;
			vec[y-1][x-1] = 1;
		}
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				cout << vec[i][j];
				if (j != n-1) {
					cout << " ";
				}
			}
			cout << endl;
		}
	}
}