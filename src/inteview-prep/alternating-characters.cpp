#include <bits/stdc++.h>
using namespace std;

// Time: O(n), Space: O(1)
int alternatingCharacters(string &a) {
	int n = a.size();
	int count = 0;
	for (int i = 0; i < n - 1; i++)
		if (a[i + 1] == a[i])
			count++;
	return count;
}

int main(void)
{
	
	return 0;
}



