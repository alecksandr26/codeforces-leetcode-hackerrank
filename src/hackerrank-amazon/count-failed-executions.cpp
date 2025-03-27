#include <bits/stdc++.h>
using namespace std;

int countFailedExecutions(vector<int> requiredSequence, vector<int> actualSequence)
{
	int i = 0, j = 0, n = requiredSequence.size();
	set<int> in;
	
	while (i < n and j < n) {
		if (in.count(requiredSequence[i])) // Ignore an already encounterd inconsistance
			i++;
		else if (requiredSequence[i] != actualSequence[j]) {
			in.insert(actualSequence[j]);
			j++;
		} else {
			i++;
			j++;
		}
	}
	
	return in.size();
}


int main(void)
{
	
	return 0;
}




