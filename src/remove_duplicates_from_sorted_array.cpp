#include <bits/stdc++.h>

#define st size_t
#define ll long long
#define ul unsigned long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define abs(a) (((a) > 0) ? (a) : -1 * (a))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))
template<typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}
using namespace std;

// url = https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		ios;
		int i, prev, n;

		prev = 1;
		n = nums.size() - 1;
		for (i = 0; i < n; i++)
			if (nums[i] < nums[i + 1])
				nums[prev++] = nums[i + 1];
		return prev;
	}
};

