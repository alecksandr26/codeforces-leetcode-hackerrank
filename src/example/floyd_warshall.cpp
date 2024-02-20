#include <bits/stdc++.h>

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;

#define N 100
#define INF ((int) 1e6)

// Adjacency list representation
int adj[N][N];

void floyd_warshall(vector<vector<int>> &distance)
{

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (i == j)
				distance[i][j] = 0;
			else if (adj[i][j])
				distance[i][j] = adj[i][j];
			else
				distance[i][j] = INF;
		}
	}
	
	for (int k = 1; k < N; k++) { // Iterate  nodes
		
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < N; j++) {
				// distance[2][4] = INF vs distance[2][1] = 5 + distance[1][4] = 9
				distance[i][j] = min(distance[i][j],
						     distance[i][k] + distance[k][j]);
				
				
			}
		}
	}
}


int main(void)
{

	
	memset(adj, 0, sizeof(int) * N * N);

	adj[1][5] = 1;
	adj[5][1] = 1;
	
	adj[1][4] = 9;
	adj[4][1] = 9;
	
	adj[1][2] = 5;
	adj[2][1] = 5;
	
	adj[4][5] = 2;
	adj[5][4] = 2;
	
	adj[4][3] = 7;
	adj[3][4] = 7;
	
	adj[2][3] = 2;
	adj[3][2] = 2;

	vector<vector<int>> distance(N, vector<int>(N, 0));
	
	floyd_warshall(distance);
	
	vector<int> nodes = {1, 2, 3, 4, 5};

	int start = 2;
	for (auto n : nodes) {
		cout << "from " << start << " to " << n << ", distance = " << distance[start][n] << endl;
	}

	return 0;
}
