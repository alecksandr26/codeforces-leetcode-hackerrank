// 2357. Make Array Zero by Subtracting Equal Amounts
// https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/description/?envType=problem-list-v2&envId=7p5x763&sorting=W3sic29ydE9yZGVyIjoiREVTQ0VORElORyIsIm9yZGVyQnkiOiJGUkVRVUVOQ1kifV0%3D&page=1

#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>

#define N ((int) 1e6)

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;
typedef long double ld;

class Solution {
public:
	// Time: O(log n * n), Space: O(1)
	int minimumOperations(vector<int>& nums)
	{
		int c = 0, n = nums.size();

		sort(nums.begin(), nums.end());
		int m = 0;
		while (m < n and nums[m] == 0)
			m++;
		int t = 0;
		if (m < n) {
			c++;
			t = nums[m];
		}

		for (int i = m; i < n; i++) {
			if (nums[i] != t) {
				c++;
				t += nums[i] - t;
			}
		}
		
		return c;
	}
};

class Solution2 {
public:
	// Time: O(n), Space: O(n)
	int minimumOperations(vector<int> &nums)
	{
		unordered_set<int> s(nums.begin(), nums.end());
		s.erase(0);
		return s.size();
	}
};


int main(void)
{
	Solution sol;

	// Write to catch the test cases
	ll n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	
	cout << sol.minimumOperations(nums) << "\n";
	
	return 0;
}










