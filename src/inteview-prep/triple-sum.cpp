#include <bits/stdc++.h>
using namespace std;



long triplets(vector<int> a, vector<int> b, vector<int> c) {
	// Sort all arrays
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	
	a.erase(unique(a.begin(), a.end()), a.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	c.erase(unique(c.begin(), c.end()), c.end());
    
	long totalTriplets = 0;
	size_t indexA = 0, indexC = 0;

	// Iterate through each element of b
	for (int q : b) {
		// Count elements in a less than or equal to q
		while (indexA < a.size() && a[indexA] <= q) {
			++indexA;
		}
		// Count elements in c less than or equal to q
		while (indexC < c.size() && c[indexC] <= q) {
			++indexC;
		}
		// Multiply counts to get number of valid triplets for this q
		totalTriplets += static_cast<long>(indexA) * static_cast<long>(indexC);
	}

	return totalTriplets;
}

int main(void)
{
	vector<int> a, b, c;

	a = {1, 4, 6};
	b = {2, 3, 3};
	c = {1, 2, 3};
	cout << triplets(a, b, c) << endl;
	return 0;
}





