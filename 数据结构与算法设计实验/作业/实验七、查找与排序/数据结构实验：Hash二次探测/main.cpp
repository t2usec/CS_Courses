#include <iostream>
#include <vector>
using namespace std;

vector<int> hash_insert(int T, const vector<int>& numbers) {
	vector<int> hash_table(T, -1); // 初始化哈希表
	vector<int> results;           // 结果列表
	
	for (int num : numbers) {
		int pos = num % T;
		if (hash_table[pos] == -1) {
			// 直接插入
			hash_table[pos] = num;
			results.push_back(pos);
		} else {
			// 发生冲突，使用二次探测
			bool found = false;
			for (int i = 1; i < T; ++i) {
				int new_pos = (pos + i * i) % T;
				if (hash_table[new_pos] == -1) {
					hash_table[new_pos] = num;
					results.push_back(new_pos);
					found = true;
					break;
				}
			}
			if (!found) {
				results.push_back(-1); // -1 表示 "Error"
			}
		}
	}
	
	return results;
}

int main() {
	int T, N;
	cin >> T >> N;
	vector<int> numbers(N);
	for (int i = 0; i < N; ++i) {
		cin >> numbers[i];
	}
	
	vector<int> result = hash_insert(T, numbers);
	for (int pos : result) {
		if (pos == -1) {
			cout << "Error" << endl;
		} else {
			cout << pos << endl;
		}
	}
	
	return 0;
}
