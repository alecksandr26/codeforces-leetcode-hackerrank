#include <bits/stdc++.h>

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;

#define N ((int) 1000)
#define INF ((int) 1e6)

// Adjacency list representation
vector<pair<int, int>> adj[N];

void dijkstras(int start, vector<int> &distance, vector<vector<int>> &shortest_paths)
{
	vector<bool> visited(N, false);
	priority_queue<pair<int, int>> q;

	for (int i = 1; i <= N; i++)
		distance[i] = INF;
	
	q.push({0, start});
	distance[start] = 0;
	shortest_paths[start].push_back(start);
	while (!q.empty()) {
		int a = q.top().second; // catch the node
		q.pop(); 	// Remove the curr node
		
		if (visited[a])
			continue;
		
		visited[a] = true;
			
		// Iterate through the row
		for (auto n : adj[a]) {
			int b = n.first, w = n.second;
			
			// Compute the distance 
			if (distance[a] + w < distance[b]) {
				// Replace the path
				distance[b] = distance[a] + w;
				shortest_paths[b] = shortest_paths[a];
				shortest_paths[b].push_back(b);
				
				// the priority queue contains negative distances to nodes. The reason
				// for this is that the default version of the C++ priority queue finds maximum
				// elements, while we want to find minimum elements.
				q.push({- distance[b], b});
			}


			
		}
	}
}


int main(void)
{
	ios;

	// adj[1].push_back({5, 1});
	// adj[1].push_back({4, 9});
	// adj[1].push_back({2, 5});
	// adj[5].push_back({4, 2});
	// adj[4].push_back({3, 6});
	// adj[2].push_back({3, 2});

	// Negative edges
	adj[1].push_back({2, 2});
	adj[1].push_back({3, 6});
	adj[2].push_back({4, 3});
	adj[3].push_back({4, -5});
	
	vector<int> distance(N, INF);
	vector<vector<int>> shortest_paths(N);
	
	int start = 1;
	dijkstras(start, distance, shortest_paths);

	vector<int> nodes = {1, 2, 3, 4};

	for (auto n : nodes) {
		cout << "from " << start << " to " << n << ", distance = " << distance[n] << endl;
	}

	for (auto end_node : nodes) {
		cout << "Shortest Path from " << start << " to " << end_node << ": ";
		for (int node : shortest_paths[end_node]) {
			cout << node << " ";
		}
		cout << endl;
	}
	
	return 0;
}







