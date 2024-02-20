#include <bits/stdc++.h>

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;

#define N ((int) 1e6)

// Adjacency list representation
vector<int> adj[N];

void bfs_shortest_path(int start, vector<vector<int>> &shortest_paths)
{
	vector<bool> visited(N, false);
	queue<int> q;

	q.push(start);
	shortest_paths[start].push_back(start);
	while (!q.empty()) {
		int curr = q.front();
		q.pop(); 	// Remove the current node
		
		// Iterate through all children
		if (!visited[curr]) {
			visited[curr] = true;
			
			for (auto nei : adj[curr]) {
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


int main(void)
{
	ios;

	adj[1].push_back(2);
	adj[2].push_back(3);
	adj[2].push_back(4);
	adj[3].push_back(4);
	adj[4].push_back(1);

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





