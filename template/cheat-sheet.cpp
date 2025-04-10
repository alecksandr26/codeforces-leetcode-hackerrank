#include <bits/stdc++.h>
using namespace std;

// ---------------- BINARY SEARCH (Iterative) ----------------
int binarySearch(const vector<int>& arr, int target) {
	int left = 0, right = arr.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == target) return mid;
		else if (arr[mid] < target) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}

// ---------------- DEPTH FIRST SEARCH (DFS) ----------------
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
	visited[node] = true;
	cout << node << " ";
	for (int neighbor : adj[node]) {
		if (!visited[neighbor]) dfs(neighbor, adj, visited);
	}
}

// ---------------- BREADTH FIRST SEARCH (BFS) ----------------
void bfs(int start, vector<vector<int>>& adj) {
	vector<bool> visited(adj.size(), false);
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int node = q.front(); q.pop();
		cout << node << " ";
		for (int neighbor : adj[node]) {
			if (!visited[neighbor]) {
				q.push(neighbor);
				visited[neighbor] = true;
			}
		}
	}
}

// ---------------- TREE TRAVERSALS ----------------
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode* root) {
	if (!root) return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

void preorder(TreeNode* root) {
	if (!root) return;
	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(TreeNode* root) {
	if (!root) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->val << " ";
}

// ---------------- DIJKSTRA'S ALGORITHM ----------------
void dijkstra(int start, vector<vector<pair<int, int>>>& graph, vector<int>& dist) {
	int n = graph.size();
	dist.assign(n, INT_MAX);
	dist[start] = 0;

	set<pair<int, int>> pq; // (distance, node)
	pq.insert({0, start});

	while (!pq.empty()) {
		auto [d, u] = *pq.begin(); pq.erase(pq.begin());

		for (auto [v, w] : graph[u]) {
			if (dist[u] + w < dist[v]) {
				pq.erase({dist[v], v});
				dist[v] = dist[u] + w;
				pq.insert({dist[v], v});
			}
		}
	}
}

