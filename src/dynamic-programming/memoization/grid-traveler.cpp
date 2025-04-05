#include <bits/stdc++.h>
using namespace std;
/*
  Say that you are a traveler on a 2D grid. You begin in the
  top-left corner and your goal is to travel to the bottom-right
  corner. You may only move down or right.
 */

struct PairHash {
    template <typename T1, typename T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1);
    }
};

class Solution {
private:
	unordered_map<pair<int, int>, int, PairHash> mem;
	
public:
	int gridTraveler(int n, int m) {
		// Base case
		if (n <= 1 or m <= 1)
			return 1;
		
		// Memoization
		if (mem.count({n, m}))
			return mem[{n, m}];
		
		// Recursive case
		return mem[{n, m}] = gridTraveler(n - 1, m) + gridTraveler(n, m - 1);
	}
};


int main(void)
{
	Solution sol;
	cout << sol.gridTraveler(4, 5) << endl;
	return 0;
}






