#include <bits/stdc++.h>
using namespace std;

// Function to calculate the minimum cost to provide library accessa
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>>& cities) {
	// If building a library is cheaper than or equal to building a road,
	// build a library in each city
	if (c_lib <= c_road) {
		return (long)n * c_lib;
	}

	// Initialize adjacency list for the graph
	vector<vector<int>> adj(n);
	for (const auto& road : cities) {
		adj[road[0] - 1].push_back(road[1] - 1);
		adj[road[1] - 1].push_back(road[0] - 1);
	}

	// Vector to track visited cities
	vector<bool> visited(n, false);
	long total_cost = 0;

	// Iterate over all cities to find connected components
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			// Count the number of cities in this connected component
			int component_size = 0;
			stack<int> s;
			s.push(i);
			visited[i] = true;
			while (!s.empty()) {
				int city = s.top();
				s.pop();
				++component_size;
				for (int neighbor : adj[city]) {
					if (!visited[neighbor]) {
						visited[neighbor] = true;
						s.push(neighbor);
					}
				}
			}
			// For each component, build one library and connect the rest with roads
			total_cost += c_lib + (component_size - 1) * c_road;
		}
	}

	return total_cost;
}


