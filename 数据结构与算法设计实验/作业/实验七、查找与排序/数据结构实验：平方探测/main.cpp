#include <iostream>
#include <vector>
using namespace std;

// 函数：插入一个值到哈希表中
void insertIntoHashTable(vector<int>& hashTable, int T, int value) {
	int index = value % T;  // 计算初始哈希位置
	int i = 0;  // 冲突次数
	
	// 尝试使用平方探测法解决冲突
	while (hashTable[index] != -1) {
		i++;
		index = (value + i*i) % T;  // 计算新的哈希位置
		if (hashTable[index] == -1) {
			break;
		}
		index = (value - i*i) % T;  // 计算另一个方向的哈希位置
		if (index < 0) index += T;  // 确保索引为非负数
	}
	
	// 插入值到哈希表中
	hashTable[index] = value;
}

int main() {
	int T, N;
	cin >> T >> N;
	vector<int> hashTable(T, -1);  // 初始化哈希表，-1 表示为空
	
	// 读取 N 个正整数并插入到哈希表中
	for (int i = 0; i < N; i++) {
		int value;
		cin >> value;
		insertIntoHashTable(hashTable, T, value);
	}
	
	// 输出哈希表中的值
	for (int i = 0; i < T; i++) {
		if (hashTable[i] == -1) {
			cout << "X";
		} else {
			cout << hashTable[i];
		}
		if (i < T - 1) {
			cout << " ";
		}
	}
	cout << endl;
	
	return 0;
}
