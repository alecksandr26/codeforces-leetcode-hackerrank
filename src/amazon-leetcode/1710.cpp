
// 1710. Maximum Units on a Truck
// https://leetcode.com/problems/maximum-units-on-a-truck/description/?envType=problem-list-v2&envId=7p5x763&sorting=W3sic29ydE9yZGVyIjoiREVTQ0VORElORyIsIm9yZGVyQnkiOiJGUkVRVUVOQ1kifV0%3D&page=1

#include <bits/stdc++.h>

#define N ((int) 1e6)

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;
typedef long double ld;


bool compare(const vector<int> &A, const vector<int> &B)
{
	return A[1] > B[1];
}


class Solution {
public:
	// Time: O(log n * n), Space: O(1)
	int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
	{
		sort(boxTypes.begin(), boxTypes.end(), compare);
		int m = 0;
		for (int i = 0; i < boxTypes.size() and truckSize; i++) {
			if (boxTypes[i][0] <= truckSize) {
				m += boxTypes[i][0] * boxTypes[i][1];
				truckSize -= boxTypes[i][0];
			} else {
				m += truckSize * boxTypes[i][1];
				truckSize = 0;
			}
		}
		return m;
	}
};


class Solution2 {
public:
	// Time: O(n), Space: O(1)
	int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
	{
		// Basically we map: units -> num of boxes
		vector<int> buckets(1001, -1);
		for (int i = 0; i < boxTypes.size(); i++) {
			if (buckets[boxTypes[i][1]] == -1) {
				buckets[boxTypes[i][1]] = boxTypes[i][0];
			} else {
				buckets[boxTypes[i][1]] += boxTypes[i][0];
			}
		}

		// Iterate from the biggest units until we fill the truck
		int ans = 0;
		for (int i = 1000; i >= 0; i--) {
			if (buckets[i] == -1)
				continue;
			if (buckets[i] <= truckSize) {
				ans += buckets[i] * i;
				truckSize -= buckets[i];
			} else {
				ans += truckSize * i;
				break;
			}
		}

		return ans;
	}
};

int main(void)
{
	Solution sol;

	// Write to catch the test cases
	
	return 0;
}



