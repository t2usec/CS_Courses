#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> tree(513, 0);

void PreOrder(int index) {
	if (tree[index] == 0 || tree.size() < index) return;
	cout << " " << tree[index];
	PreOrder(index * 2);
	PreOrder(index * 2 + 1);
}

void InOrder(int index) {
	if (tree[index] == 0 || tree.size() < index) return;
	InOrder(index * 2);
	cout << " " << tree[index];
	InOrder(index * 2 + 1);
}

void PostOrder(int index) {
	if (tree[index] == 0 || tree.size() < index) return;
	PostOrder(index * 2);
	PostOrder(index * 2 + 1);
	cout << " " << tree[index];
}

int main()
{
	int data;
	n = 1;
	while(cin>>data, data!=-1)
	{
		tree[n++] = data;
	}
	PreOrder(1);
	cout<<endl;
	InOrder(1);
	cout<<endl;
	PostOrder(1);
	cout<<endl;
	return 0;
}