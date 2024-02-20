#include <bits/stdc++.h>

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;

#define N ((int) 1e6)
#define INF ((int) 1e6)

// Adjacency list representation
vector<pair<int, int>> adj[N];

void bellman_ford(int start, vector<int> &distance, vector<vector<int>> &shortest_paths)
{
	vector<bool> visited(N, false);
	queue<int> q;

	q.push(start);
	distance[start] = 0;
	shortest_paths[start].push_back(start);
	while (!q.empty()) {
		int curr = q.front();
		q.pop(); 	// Remove the curr node
		
		if (!visited[curr]) {
			visited[curr] = true;
			
			// Iterate through the row
			for (auto n : adj[curr]) {
				q.push(n.first);

				// Compute the distance 
				if (distance[n.first] == INF
				    || (distance[n.first] > distance[curr] + n.second)) {
					// Replace the path
					distance[n.first] = distance[curr] + n.second;
					shortest_paths[n.first] = shortest_paths[curr];
					shortest_paths[n.first].push_back(n.first);
				
				}
			}
		}
	}
}



int main(void)
{
	ios;

	adj[1].push_back({2, 5});
	adj[2].push_back({3, 7});
	adj[2].push_back({4, 9});
	adj[3].push_back({4, 1});
	adj[4].push_back({1, 2});
	
	vector<int> distance(N, INF);
	vector<vector<int>> shortest_paths(N);

	int start_node = 1;
	bellman_ford(start_node, distance, shortest_paths);
	
	for (size_t i = 1; i <= 4; i++) {
		cout << "from " << start_node << " to " << i << ", distance = " << distance[i] << endl;
	}
	

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

