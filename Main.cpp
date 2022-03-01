// DFS, BFS
#include<iostream>
#include<list>
#include<vector>
#include<queue>

struct Node {
	int id;
	int value;
	std::list<int> neighbours;
};

void dfs(int id, bool* visited, const std::vector<Node*>& graph) {
	visited[id] = true;
	std::cout << graph[id]->value << std::endl;
	for (auto it = graph[id]->neighbours.cbegin(); it != graph[id]->neighbours.cend(); it++)
	{
		if (!visited[*it]) dfs(*it, visited, graph);
	}
}

void bfs(int id, bool* visited, const std::vector<Node*>& graph) {
	std::queue<int> queue;
	int current = id;
	queue.push(current);
	visited[current] = true;
	
	while (!queue.empty()) {
		current = queue.front();
		queue.pop();
		std::cout << graph[current]->value << std::endl;
		for (auto it = graph[current]->neighbours.cbegin(); it != graph[current]->neighbours.cend(); it++) {
			if (!visited[*it]) {
				visited[*it] = true;
				queue.push(*it);
			}
		}
	}
}

int main() {
	std::vector<Node*> graph;
	int n;
	std::cin >> n;
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
		int degree, value;
		std::cin >> degree >> value;
		Node* vertex = new Node();
		vertex->value = value;
		vertex->id = i;
		for (int j = 0; j < degree; j++)
		{
			int neighbourID;
			std::cin >> neighbourID;
			vertex->neighbours.push_back(neighbourID);
		}
		graph.push_back(vertex);
	}
	bfs(0, visited, graph);
	return 0;
}