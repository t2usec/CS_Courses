#include <iostream>
#include <list>
using namespace std;

int main() {
	int T, n, p, pos, m, val;
	cin >> T; // 读取测试组数
	while (T--) {
		list<int> l;
		cin >> n; // 读取线性表的初始元素个数
		for (int i = 0; i < n; ++i) {
			cin >> val;
			l.push_back(val); // 将元素添加到线性表中
		}
		cin >> p; // 读取操作的次数
		while (p--) {
			string op;
			cin >> op;
			if (op == "insert") {
				cin >> pos >> m;
				auto it = l.begin();
				advance(it, pos - 1); // 移动迭代器到指定位置
				for (int i = 0; i < m; ++i) {
					cin >> val;
					l.insert(it, val); // 插入元素
				}
			} else if (op == "delete") {
				cin >> pos >> m;
				auto it = l.begin();
				advance(it, pos - 1); // 移动迭代器到指定位置
				while (m-- && it != l.end()) {
					it = l.erase(it); // 删除元素
				}
			}
		}
		auto it = l.begin();
		while(it!=l.end()){
			cout << *it;
			if (next(it) != l.end()) {
				cout << " ";
			}
			it++;
		}
		cout << endl;
	}
	return 0;
}
