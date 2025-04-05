/*
  Can sum tabulation version
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	// Time: O(t * n), space: O(t)
	bool canSum(int target, vector<int> &A) {
		bool tab[target + 1];
		memset(tab, false, sizeof(bool) * (target + 1));
		
		tab[0] = true;
		for (int i = 0; i <= target; i++)
			if (tab[i])
				for (const auto &a : A)
					if (i + a <= target)
						tab[i + a] = true;
		return tab[target];
	}
};


int main(void)
{
	Solution sol;
	// vector<int> A = {5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7, 5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7, 5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7, 5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7};
	vector<int> A = {9, 1, 2, 2, 4};
	cout << sol.canSum(7, A) << endl;
	
        return 0;
}
