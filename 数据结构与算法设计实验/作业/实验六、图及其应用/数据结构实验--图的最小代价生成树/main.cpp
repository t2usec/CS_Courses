#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int u; 
	int v;  
	int weight; 
	
	bool operator<(const Edge& e) const {
		return weight > e.weight;  
	}
};

void Prim(vector<vector<int>>& graph, int n) {
	vector<bool> visited(n + 1, false); // 记录顶点是否已访问
	priority_queue<Edge> pq; 
	
	visited[1] = true; // 从顶点1开始扩展
	for (int i = 2; i <= n; i++) {
		if (graph[1][i] != -1) { 
			pq.push({1, i, graph[1][i]});
		}
	}
	
	while (!pq.empty()) {
		Edge e = pq.top();
		pq.pop();
		
		if (visited[e.v]) {
			continue;  
		}
		
		visited[e.v] = true;
		cout << e.u << " " << e.v << " " << e.weight << endl;
		
		for (int i = 1; i <= n; i++) {
			if (!visited[i] && graph[e.v][i] != -1) {
				pq.push({e.v, i, graph[e.v][i]});
			}
		}
	}
}

int main() {
	int n, e;
	while (cin >> n >> e) {
		vector<vector<int>> graph(n + 1, vector<int>(n + 1, -1)); // 初始化邻接矩阵，-1代表没有边
		for (int i = 0; i < e; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			graph[u][v] = w;
			graph[v][u] = w;
		}
		Prim(graph, n);
	}
	return 0;
}
