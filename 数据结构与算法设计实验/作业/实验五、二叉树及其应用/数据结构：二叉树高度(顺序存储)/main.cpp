#include <bits/stdc++.h>

using namespace std;

int Height(int tree[], int n) {
	function<int(int, int)> calculateHeight = [&](int i, int level) -> int {
		if (i >= n || tree[i] == 0) return level;
		return max(calculateHeight(2 * i + 1, level + 1), calculateHeight(2 * i + 2, level + 1));
	};
	return calculateHeight(0, 0);
}

int main()
{
	int tree[512], n = 0;
	int data;
	while(cin>>data, data!=-1)
	{
		tree[n++] = data;
	}
	cout<<Height(tree, n)<<endl;
	return 0;
}