#include <bits/stdc++.h>
using namespace std;





double getMedian(vector<int> &count, int d) {
	int sum = 0;
	if (d % 2 != 0) {
		int medianPos = d / 2 + 1;
		for (int i = 0; i < 201; i++) {
			sum += count[i];
			if (sum >= medianPos)
				return (double) i;
		}
	} else {
		int first = -1, second = -1;
		int m1 = d / 2, m2 = d / 2 + 1;
		for (int i = 0; i < 201; i++) {
			sum += count[i];
			if (sum >= m1 && first == -1)
				first = i;
			if (sum >= m2) {
				second = i;
				break;
			}
		}
		return (double) (first + second) / 2;
	}
	return 0.0;
}

int activityNotifications(vector<int> &exp, int d) {
	vector<int> count(201, 0);
	for (int i = 0; i < d; i++)
		count[exp[i]]++;
	
	int notif = 0;
	for (int i = d; i < exp.size(); i++) {
		double median = getMedian(count, d);
		if ((double) exp[i] >= 2 * median)
			notif++;
		count[exp[i - d]]--;
		count[exp[i]]++;
	}

	return notif;
}

int main(void)
{
	vector<int> exp;
	int d;
	
	// d = 5;
	// exp = {2, 3, 4, 2, 3, 6, 8, 4, 5};
	// cout << activityNotifications(exp, d) << endl;

	// d = 4;
	// exp = {1, 2, 3, 4, 4};
	// cout << activityNotifications(exp, d) << endl;
	
	d = 3;
	exp = {10, 20, 30, 40, 50};
	cout << activityNotifications(exp, d) << endl;
	
	
	return 0;
}


