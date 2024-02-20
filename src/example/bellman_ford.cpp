#include <bits/stdc++.h>

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;

#define N ((int) 10000)
#define INF ((int) 1e6)

vector<tuple<int, int, int>> edges;

void bellman_ford(int start, vector<int> &distance)
{
	for (int i = 1; i <= N; i++)
		distance[i] = INF;

	distance[start] = 0;
	for (int i = 1; i <= N - 1; i++) {
		for (auto e : edges) {
			int a, b, w;
			tie(a, b, w) = e;
			distance[b] = min(distance[b], distance[a] + w);
		}
	}
}


void bellman_ford_shortest_path(int start, vector<int> &distance, vector<vector<int>> &shortest_paths)
{
	for (int i = 1; i <= N; i++)
		distance[i] = INF;

	distance[start] = 0;
	shortest_paths[start].push_back(start);
	for (int i = 1; i <= N - 1; i++) {
		for (auto e : edges) {
			int a, b, w;
			tie(a, b, w) = e;
			if (distance[b] > distance[a] + w) {
				// Replace the path
				distance[b] = distance[a] + w;
				shortest_paths[b] = shortest_paths[a];
				shortest_paths[b].push_back(b);
			}
		}
	}
}

int main(void)
{
	ios;

	// edges.push_back({3, 4, 5});
	// edges.push_back({2, 4, 6});
	// edges.push_back({1, 2, 5});
	// edges.push_back({2, 3, 7});
	// edges.push_back({4, 1, 2});

	// Negative cycle
	edges.push_back({1, 2, 3});
	edges.push_back({2, 3, 2});
	edges.push_back({3, 4, -7});
	edges.push_back({3, 1, 5});

	// To make the cycle
	edges.push_back({4, 2, 1}); 

	
	
	vector<int> distance(N + 1, INF);


	int start = 1;
	bellman_ford(start, distance);

	for (size_t i = 1; i <= 4; i++) {
		cout << "from " << start << " to " << i << ", distance = " << distance[i] << endl;
	}

	

	vector<vector<int>> shortest_paths(N);
	bellman_ford_shortest_path(start, distance, shortest_paths);

	vector<int> nodes = {1, 2, 3, 4};

	for (auto end_node : nodes) {
		cout << "Shortest Path from " << start << " to " << end_node << ": ";
		for (int node : shortest_paths[end_node]) {
			cout << node << " ";
		}
		cout << endl;
	}
	
	return 0;
}



