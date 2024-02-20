#include <bits/stdc++.h>

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;

#define N 100

// Adjacency matrix representation
int adj[N][N];

void bfs_shortest_path(int start, vector<vector<int>> &shortest_paths)
{
	vector<bool> visited(N, false);
	queue<int> q;
	
	q.push(start);
	shortest_paths[start].push_back(start);
	while (!q.empty()) {
		int curr = q.front();
		q.pop(); 	// Remove the curr node

		// Iterate through the row
		if (!visited[curr]) {
			visited[curr] = true;
			for (size_t nei = 0; nei < N; nei++) {
				if (adj[curr][nei]) {
					q.push(nei);
				
					if (shortest_paths[nei].size() == 0
					    || shortest_paths[nei].size() > shortest_paths[curr].size() + 1) {
						// Replace the path
						shortest_paths[nei] = shortest_paths[curr];
						shortest_paths[nei].push_back(nei);
					}
				}
			}
		}
	}
}

int main(void)
{
	ios;

	memset(adj, 0, sizeof(int) * N * N);
	
	adj[1][2] = 1;
	adj[2][3] = 1;
	adj[2][4] = 1;
	adj[3][4] = 1;
	adj[4][1] = 1;

	int start_node = 1;
	vector<vector<int>> shortest_paths(N);
	
	bfs_shortest_path(start_node, shortest_paths);

	vector<int> nodes = {1, 2, 3, 4};

	for (auto end_node : nodes) {
		cout << "Shortest Path from " << start_node << " to " << end_node << ": ";
		for (int node : shortest_paths[end_node]) {
			cout << node << " ";
		}
		cout << endl;
	}
	
	return 0;
}





