#include <bits/stdc++.h>
using namespace std;

int countPromotionalPeriods(vector<int> orders)
{
	int count = 0, n = orders.size();

	for (int i = 0; i < n - 1; i++)
		if (orders[i] > orders[i + 1]) {
			int k = orders[i + 1];
			for (int j = i + 1; j < n - 1; j++) {
				k = max(orders[j], k);
				if (k < min(orders[i], orders[j + 1]))
					count++;
			}
		}

	return count;
}



int main(void)
{
	
	return 0;
}


