#include <bits/stdc++.h>
using namespace std;

// Time: O(n log n), Space: O(1)
int maximumToys(vector<int> &p, int k) {
	sort(p.begin(), p.end());
	int n = p.size();

	int count = 0;
	for (int i = 0; i < n; i++)
		if (k >= p[i]) {
			k -= p[i];
			count++;
		}
			
	return count;
}


int main(void)
{
	vector<int> p = {1, 12, 5, 111, 200, 1000, 10};
	int k = 50;
	
	cout << maximumToys(p, k) << endl;
	
	
	return 0;
}




