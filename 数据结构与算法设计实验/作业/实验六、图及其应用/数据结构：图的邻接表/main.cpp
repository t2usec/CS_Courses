#include <bits/stdc++.h>

using namespace std;

class ArcNode {
public:
	int vertex;
	ArcNode* next;
};

class Graph {
public:
	int vNum;
	int eNum;
	ArcNode *head[21];
};

void CreateGraph(Graph& g) {
	cin >> g.vNum >> g.eNum;
	for (int i=1; i<g.vNum+1; i++) {
		ArcNode* newNode = new ArcNode;
		newNode->vertex = i;
		newNode->next = NULL;
		g.head[i] = newNode;
	}
	for (int i=0; i<g.eNum; i++) {
		int a, b;
		cin >> a >> b;
		ArcNode* tail = g.head[a];
		while (tail->next && tail->next->vertex < b) {
			tail = tail->next;
		}
		ArcNode* newNode = new ArcNode;
		newNode->vertex = b;
		newNode->next = NULL;
		if (tail->next) {
			newNode->next = tail->next;
		}
		tail->next = newNode;
	}
	for (int i=1; i<g.vNum+1; i++) {
		g.head[i] = g.head[i]->next;
	}
}

void PrintGraph(Graph& g) {
	int i;
	for(i=1; i<=g.vNum; i++)
	{
		ArcNode *p = g.head[i];
		printf("%d", i);
		while(p)
		{
			printf("->%d", p->vertex);
			p = p->next;
		}
		printf("\n");
	}
}

int main() {
	Graph g;
	CreateGraph(g);
	PrintGraph(g);
	return 0;
}