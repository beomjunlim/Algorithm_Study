#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct Node{
	int cnt, a, b;

	bool operator<(const Node& other) const {
		if (cnt != other.cnt)
			return cnt < other.cnt;
	}
};

int V, E;
vector<Node> node;
bool visited[10001];
int parent[10001];

int findParent(int x) {
	if (parent[x] != x)
		parent[x] = findParent(parent[x]);
	return parent[x];
}

void unite(int x, int y) {
	int X = findParent(x);
	int Y = findParent(y);

	if (X != Y)
		parent[Y] = X;
}

int main() {
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		node.push_back({ c,a,b });
	}

	sort(node.begin(), node.end());

	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	int weight = 0;
	int count = 0;
	for (int i = 0; i < node.size(); i++) {
		if (findParent(node[i].a) != findParent(node[i].b)) {
			unite(node[i].a, node[i].b);
			count++;
			weight += node[i].cnt;
			if (count == V - 1)
				break;
		}
	}
	cout << weight;

}
