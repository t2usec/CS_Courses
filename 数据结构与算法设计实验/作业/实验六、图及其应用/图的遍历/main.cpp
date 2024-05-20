#include <bits/stdc++.h>
#define Graph vector<vector<int>>
using namespace std;

unordered_set<int> dfs_visited;

void dfs(int n, Graph& g) {
	if (dfs_visited.count(n)) {
		return;
	}
	cout << n << " ";
	dfs_visited.insert(n);
	for (int i=0; i<g[n-1].size(); i++) {
		if (g[n-1][i]) {
			dfs(i+1, g);
		}
	}
}

void bfs(Graph& g) {
	unordered_set<int> bfs_visited;
	queue<int> q;
	q.push(1);
	bfs_visited.insert(1);
	while(!q.empty()){
		int target = q.front();
		q.pop();
		cout << target << " ";
		for (int i=0; i<g[target-1].size(); i++) {
			if (g[target-1][i] && !bfs_visited.count(i+1)) {
				q.push(i+1);
				bfs_visited.insert(i+1);
			}
		}
	}
} 

Graph CreateGraph(int n, int e) {
	Graph vec(n, vector<int>(n));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			vec[i][j] = 0;
		}
	}
	for (int i=0; i<e; i++) {
		int a, b;
		cin >> a >> b;
		vec[a-1][b-1] = 1;
		vec[b-1][a-1] = 1;
	}
	return vec;
}

void PrintGraph(Graph& g) {
	for (int i=0; i<g.size(); i++) {
		for (int j=0; j<g.size(); j++) {
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int n, e;
	while(scanf("%d %d", &n, &e) != EOF){
		Graph g = CreateGraph(n, e);
		dfs_visited.clear();
		dfs(1, g);
		cout << endl;
		bfs(g);
		cout << endl;
	}
}