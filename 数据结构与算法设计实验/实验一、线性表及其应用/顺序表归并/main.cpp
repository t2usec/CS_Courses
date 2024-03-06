#include <iostream>
#include <vector>

using namespace std;

void mergeLists(vector<int>& va, vector<int>& vb, vector<int>& vc) {
	int i = 0, j = 0;
	while (i < va.size() && j < vb.size()) {
		if (va[i] <= vb[j]) {
			vc.push_back(va[i]);
			i++;
		} else {
			vc.push_back(vb[j]);
			j++;
		}
	}
	
	while (i < va.size()) {
		vc.push_back(va[i]);
		i++;
	}
	
	while (j < vb.size()) {
		vc.push_back(vb[j]);
		j++;
	}
}

int main() {
	int n;
	cin >> n;
	
	for (int k = 0; k < n; k++) {
		int m, num;
		cin >> m;
		vector<int> va(m);
		for (int i = 0; i < m; i++) {
			cin >> num;
			va[i] = num;
		}
		
		cin >> m;
		vector<int> vb(m);
		for (int i = 0; i < m; i++) {
			cin >> num;
			vb[i] = num;
		}
		
		vector<int> vc;
		mergeLists(va, vb, vc);
		
		cout << vc.size() << " ";
		for (int i = 0; i < vc.size(); i++) {
			if (i == vc.size()-1) {
				cout << vc[i];
				continue;
			}
			cout << vc[i] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
