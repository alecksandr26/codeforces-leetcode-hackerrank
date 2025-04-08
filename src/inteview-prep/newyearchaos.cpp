#include <bits/stdc++.h>
using namespace std;



void minimumBribes(vector<int> &q) {
	int n = q.size(), count = 0;
	for (int i = 0; i < n; i++) {
		int distance = q[i] - (i + 1);
		if (distance > 2) {
			cout << "Too chaotic" << endl;
			return;
		}

		for (int j = max(0, q[i] - 2); j < i; j++)
			if (q[j] > q[i]) count++;
	}
	cout << count << endl;
}


int main(void)
{
	vector<int> q;
	q = {2, 1, 5, 3, 4};
	minimumBribes(q);

	q = {2, 5, 1, 3, 4};
	minimumBribes(q);

	q = {1, 2, 5, 3, 7, 8, 6, 4};
	minimumBribes(q);
	
	return 0;
}




