#include <bits/stdc++.h>
using namespace std;


void countSwaps(vector<int> &A) {
	int n = A.size();
	int num_swaps = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			// Swap adjacent elements if they are in decreasing order
			if (A[j] > A[j + 1]) {
				swap(A[j], A[j + 1]);
				num_swaps++;
			}
		}
	}

	cout << "Array is sorted in " << num_swaps << " swaps." << endl;
	cout << "First Element: " << A[0] << endl;
	cout << "Last Element: " << A[n - 1] << endl;
}

int main(void)
{
	vector<int> A = {1, 2, 3};
	countSwaps(A);
	return 0;
}





