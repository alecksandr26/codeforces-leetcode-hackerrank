
/*
  Say that you are a traveler on a 2D grid. You begin in the
  top-left corner and your goal is to travel to the bottom-right
  corner. You may only move down or right.
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	
public:
	int gridTraveler(int n, int m) {
		int tab[n][m];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (i == 0 or j == 0 and not (i == 0 and j == 0))
					tab[i][j] = 1;
				else tab[i][j] = 0;
			}
		for (int i = 1; i < n; i++)
			for (int j = 1; j < m; j++)
				tab[i][j] += tab[i - 1][j] + tab[i][j - 1];
		return tab[n - 1][m - 1];
	}
};


int main(void)
{
	Solution sol;
	cout << sol.gridTraveler(4, 5) << endl;
	return 0;
}

