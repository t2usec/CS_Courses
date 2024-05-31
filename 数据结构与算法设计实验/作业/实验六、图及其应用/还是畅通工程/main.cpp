#include <bits/stdc++.h>
#define Graph vector<vector<int>>
#define INF 0x3f3f3f3f
using namespace std;

/*
Prim 算法实现对应主程序
cout << Prim(graph) << endl;
*/
int Prim(Graph& graph) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 优先队列，将较短距离的点提前
	unordered_set<int> visited; // 集合，存储已经访问过的点
	
	int total_cost = 0; // 总消耗
	
	pq.push({0, 0});
	
	while (!pq.empty()) {
		pair<int, int> top = pq.top();
		pq.pop();
		
		int u = top.second;
		if (visited.count(u)) {
			continue; // 如果已经访问过该点，则略过
		}
		
		visited.insert(u); // 本次访问，添加进 visited
		total_cost += top.first;
		
		for (int v = 0; v < graph[u].size(); ++v) {
			if (!visited.count(v) && graph[u][v] != INF) { // 未曾到过且路径存在
				pq.push({graph[u][v], v}); // 从 0 开始到 v 的最短路径
			}
		}
	}
	return total_cost;
}


/*
并查集，用于 Kruskal 算法
{1,2,3} -> 1
{4,5,6} -> 4
{1,2,3}U{4,5,6} -> 1
*/
class UnionFind {
public:
	vector<int> p;
	UnionFind(int n) {
		for (int i=0; i<n; i++) {
			p.push_back(i);
		}
	}
	int find(int x) {
		if (x != p[x]) {
			p[x] = find(p[x]);
		}
		return p[x];
	}
	void unite(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);
		if (rootX != rootY) {
			p[rootX] = rootY;
		}
	}
};

/*
Kruskal 算法实现对应主程序
cout << Kruskal(graph) << endl;
*/
int Kruskal(Graph& graph) {
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	UnionFind uf(graph.size());
	
	int total_cost = 0;
	
	for (int i=0; i<graph.size(); i++) {
		for (int j=0; j<graph[i].size(); j++) {
			pq.push({graph[i][j], i, j});
		}
	}
	
	while(!pq.empty()){
		vector<int> t = pq.top();
		pq.pop();
		
		if (uf.find(t[1]) == uf.find(t[2])) {
			continue; // 如果形成环，则跳过
		}
		
		uf.unite(t[1], t[2]);
		
		total_cost += t[0];
	}
	
	return total_cost;
}

int main() {
	int N;
	while (cin >> N && N != 0) {
		
		Graph graph(N, vector<int>(N, INF)); // 表示从 1 开始到 N 的
		
		for (int i = 0; i < N; ++i) {
			graph[i][i] = 0; // 自己到自己的距离是 0
		}
		
		for (int i = 0; i < N * (N - 1) / 2; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			graph[a-1][b-1] = graph[b-1][a-1] = d;
		}
		
		cout << Kruskal(graph) << endl;
		// cout << Prim(graph) << endl;
	}
	return 0;
}

