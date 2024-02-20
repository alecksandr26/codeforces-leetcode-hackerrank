#include <bits/stdc++.h>

#define N ((int) 1e6)

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;

// problem: https://codeforces.com/problemset/problem/59/E
vector<int> adj[N];

void bfs(int start, vector<vector<int>> &paths)
{
	vector<bool> visited(N, false);
	queue<int> q;

	q.push(start);
	paths[start].push_back(start);
	while (!q.empty()) {
		int curr = q.front();
		q.pop(); 	// Remove the current node
		
		// Iterate through all children
		if (visited[curr])
			continue;
		
		visited[curr] = true;
			
		for (auto nei : adj[curr]) {
			q.push(nei);
				
			if (paths[nei].size() == 0
			    || paths[nei].size() > paths[curr].size() + 1) {
				// Replace the path
				paths[nei] = paths[curr];
				paths[nei].push_back(nei);
			}
		}
	}
}

int main(void)
{
	ios;
	
	int n, m, k;

	cin >> n >> m >> k;


	while (m--) {
		int x, y;
		cin >> x >> y;
		
		adj[x].push_back(y);
		adj[y].push_back(x);
		
	}

	vector<tuple<int, int, int>> v;
	while (k--) {
		int a, b, c;
		cin >> a >> b >> c;
		
		v.push_back({a, b, c});
	}


	vector<vector<int>> paths(n);
	int start_node = 1;
	bfs(start_node, paths);

	
	for (int end_node = 1; end_node <= n; end_node++) {
		cout << "Shortest Path from " << start_node << " to " << end_node << ": ";
		for (int node : paths[end_node]) {
			cout << node << " ";
		}
		cout << endl;
	}
	
	
	return 0;
}



