#include <bits/stdc++.h>
using namespace std;


// Merge two sorted subarrays into one
long merge(vector<int>& A, int left, int mid, int right) {
	// Copy
	vector<int> leftPart(A.begin() + left, A.begin() + mid + 1);
	vector<int> rightPart(A.begin() + mid + 1, A.begin() + right + 1);
	
	long swaps = 0;
	int i = 0, j = 0, k = left;
	while (i < leftPart.size() && j < rightPart.size()) {
		if (leftPart[i] <= rightPart[j]) {
			A[k++] = leftPart[i++];
		} else {
			A[k++] = rightPart[j++];
			swaps += leftPart.size() - i;
		}
	}

	// Copy remaining elements
	while (i < leftPart.size()) {
		A[k++] = leftPart[i++];
	}
	while (j < rightPart.size()) {
		A[k++] = rightPart[j++];
	}

	return swaps;
}

// Recursive merge sort
long mergeSort(vector<int>& A, int left, int right) {
	if (left >= right)
		return 0;
	
	int mid = left + (right - left) / 2;

	long swaps = 0;
	swaps += mergeSort(A, left, mid);
	swaps += mergeSort(A, mid + 1, right);
	
	return swaps + merge(A, left, mid, right);
}

long countInversions(vector<int> &A) {

	return mergeSort(A, 0, A.size() - 1);
}

int main(void)
{
	vector<int> A;
	
	A = {1, 1, 1, 2, 2};
	cout << countInversions(A) << endl;


	A = {2, 1, 3, 1, 2};
	cout << countInversions(A) << endl;
		
	return 0;
}







