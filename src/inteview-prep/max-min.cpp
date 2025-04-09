#include <bits/stdc++.h>
using namespace std;

int maxMin(int k, vector<int> &A) {
	sort(A.begin(), A.end());
	int n = A.size();
	int minimum = INT_MAX;
	for (int i = 0; i <= n - k; i++)
		minimum = min(A[k + i - 1] - A[i], minimum);
	return minimum;
}

int main(void)
{
	
	return 0;
}





