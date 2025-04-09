#include <bits/stdc++.h>
using namespace std;

int luckBalance(int k, vector<vector<int>> contests) {
	long luck = 0;

	vector<int> importantLuck;
	for (int i = 0; i < contests.size(); i++) {
		if (contests[i][1])
			importantLuck.push_back(contests[i][0]);
		else luck += contests[i][0];
	}
	if (importantLuck.empty())
		return luck;

	int n = importantLuck.size();

	sort(importantLuck.begin(), importantLuck.end());
	for (int i = n - 1; i >= 0 and i >= n - k; i--)
		luck += importantLuck[i];

	for (int i = 0; i < n - k; i++)
		luck -= importantLuck[i];

	return luck;
}

int main(void)
{
	
	return 0;
}




