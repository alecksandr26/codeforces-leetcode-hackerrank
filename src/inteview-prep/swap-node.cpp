#include <bits/stdc++.h>
using namespace std;


void inOrderSwap(vector<vector<int>> &indexes, vector<int> &out, int k, int currIndex = 0, int depth = 0) {
	if ((depth + 1) % k == 0)
		swap(indexes[currIndex][0], indexes[currIndex][1]);
	
	int left = indexes[currIndex][0], right = indexes[currIndex][1];
	if (left > -1)
		inOrderSwap(indexes, out, k, left - 1, depth + 1);
	out.push_back(currIndex + 1);
	if (right > -1)
		inOrderSwap(indexes, out, k, right - 1, depth + 1);
}

vector<vector<int>> swapNodes(vector<vector<int>> &indexes, const vector<int> &queries) {
	vector<vector<int>> ans;
	for (const auto &k : queries) {
		vector<int> out;
		inOrderSwap(indexes, out, k);
		ans.push_back(out);
	}
	return ans;
}

int main(void) {
	vector<vector<int>> indexes;
	vector<int> queries;
	
	indexes = {
		{3, 2},
		{-1, -1},
		{-1, -1}
	};
	queries = {1, 1};
	vector<vector<int>> output = swapNodes(indexes, queries);

	for (const auto &vec : output) {
		for (const auto &num : vec)
			cout << num << " ";
		cout << endl;
	}
	
	
	return 0;
}
