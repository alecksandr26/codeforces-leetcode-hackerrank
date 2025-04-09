#include <bits/stdc++.h>
using namespace std;


int getMinimumCost(int k, vector<int> &c) {
	sort(c.begin(), c.end());
	int n = c.size();
	int purchases = 0;
	int minimum = 0;
	for (int i = n - k; i >= 0 and i >= n % k; i -= k) {
		for (int j = i; j < i + k; j++)
			minimum += (purchases + 1) * c[j];
		purchases++;
	}
	for (int i = 0; i < n % k; i++)
		minimum += (purchases + 1) * c[i];
	
	return minimum;
}

int main(void)
{
	return 0;
}








