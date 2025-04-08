#include <bits/stdc++.h>
#include <vector>
using namespace std;



// Time: O(n^2), Space: O(1)
int minimumSwaps(vector<int> &A) {
	int numSwaps = 0;
	for (int i = 0; i < A.size() - 1; i++) {
		if (A[i] != i + 1) {
			int minIndex = -1;
			for (int j = i; j < A.size(); j++)
				if (i + 1 == A[j]) {
					minIndex = j;
					break;
				}
			swap(A[minIndex], A[i]);
			numSwaps++;
		}
	}
	return numSwaps;
}

int main(void)
{
	vector<int> A;
	A = {7, 1, 3, 2, 4, 5, 6};

	cout << minimumSwaps(A) << endl;
	
	return 0;
}




