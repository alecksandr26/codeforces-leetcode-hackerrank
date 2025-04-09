#include <bits/stdc++.h>
using namespace std;


int minimumAbsoluteDifference(vector<int> &A) {
	sort(A.begin(), A.end());
	int n = A.size();
	int minimum = abs(A[1] - A[0]);
	for (int i = 1; i < n - 1; i++) {
		minimum = min(minimum, abs(A[i + 1] - A[i]));
		if (minimum == 0)
			break;
	}
	return minimum;
}


int main(void)
{
	
	return 0;
}





