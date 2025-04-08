/*
  https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays
*/

#include <bits/stdc++.h>
using namespace std;


#define N 6
int hourglassSum(vector<vector<int>> &A) {
	int m = INT_MIN;
	for (int i = 0; i <= N - 3 ; i++) {
		for (int j = 0; j <= N - 3; j++) {
			// Sum the hourglass

			// sum a + b + c
			int sum = A[i][j] + A[i][j + 1] + A[i][j + 2];
			// sum d
			sum += A[i + 1][j + 1];
			// sum e + f +  g
			sum += A[i + 2][j] + A[i + 2][j + 1] + A[i + 2][j + 2];

			m = max(m, sum);
		}
	}
	return m;
}


int main(void)
{
	vector<vector<int>> A;
	A = {{-9, -9, -9,  1, 1, 1},
	     {0, -9,  0,  4, 3, 2},
	     {-9, -9, -9,  1, 2, 3},
	     {0, 0, 8, 6, 6, 0},
	     {0, 0, 0, -2, 0, 0},
	     {0, 0, 1, 2, 4, 0}};

	int ans = hourglassSum(A);
	cout << ans << endl;
	
	return 0;
}






