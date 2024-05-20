#include <bits/stdc++.h>
#define Graph vector<vector<int>>
#define INF 0x3f3f3f3f

using namespace std;

/*
Dijkstra 算法实现对应主程序

int main() {
	int n;
	while(scanf("%d", &n) != EOF, n != 0){
		Graph g = CreateGraph(n);
		int k;
		cin >> k;
		vector<int> dist(n, INF); // 存储从源节点到图中每个其他节点的当前已知最短路径长度
		Dijkstra(g, 0, dist);
		if (dist[k] != INF) {
			cout << dist[k];
		} else {
			cout << "NO WAY!";
		}
		cout << endl;
	}
}
*/
void Dijkstra(const Graph& g, int s, vector<int>& dist) {
	dist[s] = 0; // 源点到自身的距离设置为0
	
	/*
	将源点放入优先队列，0 是距离，s 是节点
	即目前已知的是 s->s 距离为 0
	后续优先处理距离最小的节点
	第一个值的作用是帮助优先队列进行排序
	*/
	priority_queue</* 队列中元素的类型 */ pair<int, int>, /* 底层容器 */ vector<pair<int, int>>, /* 比较器 */ greater<pair<int, int>>> pq;
	pq.push({0, s});
	
	while (!pq.empty()) {
		int u = pq.top().second; // 从优先队列中取出距离最小的节点（第一次就是 s）
		pq.pop();
		for (int v = 0; v < g[u].size(); ++v) {
			if (g[u][v] != INF) { // 如果节点u和节点v之间有边
				int alt = dist[u] + g[u][v]; // 计算 s->u + u->v 的距离
				if (alt < dist[v]) { // 如果 s->u + u->v 比已知距离短
					/*
					先更新 s->v 的最短距离
					又因为 s->v 的最短距离发生了更新，所以添加回优先队列
					重新计算 s->v->其他节点 的距离
					*/
					dist[v] = alt;
					pq.push({alt, v});
				}
			}
		}
	}
}

/*
Floyd 算法实现对应主程序

int main() {
	int n;
	while(scanf("%d", &n) != EOF, n != 0){
		Graph g = CreateGraph(n);
		int k;
		cin >> k;
		vector<vector<int>> fly = Floyd(g);
		if (fly[0][k] != INF) {
			cout << fly[0][k];
		} else {
			cout << "NO WAY!";
		}
		cout << endl;
	}
}
*/
vector<vector<int>> Floyd(const Graph& g) {
	vector<vector<int>> vec(g.size(), vector<int>(g.size(), INF)); // 这里其实就是把图复制了一份，Floyd 算法可以直接在图上操作
	for (int i=0; i<g.size(); i++) {
		for (int j=0; j<g[i].size(); j++) {
			vec[i][j] = g[i][j];
		}
	}
	for(int k=0; k<g.size(); k++) { // 枚举中转点（一定要先枚举中转点）
		for(int i=0; i<g.size(); i++) { // 枚举起点
			for(int j=0; j<g.size(); j++) { // 枚举终点
				if(vec[i][k] + vec[k][j] < vec[i][j]) { // 如果经过中转点可以使直接从 i 到 j 的权值减少
					vec[i][j] = vec[i][k] + vec[k][j]; // 则进行松弛操作
				}
			}
		}
	}
	return vec;
}

Graph CreateGraph(int n) {
	Graph g(n, vector<int>(n, INF));
	int a, b, t;
	while(scanf("%d %d %d", &a, &b, &t), !(a==0 && b==0 && t==0)){
		g[a][b] = t;
	}
	return g;
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF, n != 0){
		Graph g = CreateGraph(n);
		int k;
		cin >> k;
		vector<int> dist(n, INF); // 存储从源节点到图中每个其他节点的当前已知最短路径长度
		Dijkstra(g, 0, dist);
		if (dist[k] != INF) {
			cout << dist[k];
		} else {
			cout << "NO WAY!";
		}
		cout << endl;
	}
}