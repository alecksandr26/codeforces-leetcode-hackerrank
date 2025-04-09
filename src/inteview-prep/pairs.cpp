#include <bits/stdc++.h>
using namespace std;

int pairs(int k, vector<int> arr) {
	unordered_set<int> set(arr.begin(), arr.end());
	int count = 0;
	for (const auto &e : arr)
		if (set.count(k + e))
			count++;
	return count;
}

int main(void) {
	
	return 0;
}









