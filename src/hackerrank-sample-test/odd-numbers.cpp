#include <bits/stdc++.h>
using namespace std;

vector<int> oddNumbers(int l, int r)
{
	vector<int> odds;
	for (int i = l; i <= r; i++)
		if (i % 2 != 0)
			odds.push_back(i);
	return odds;
}

int main(void)
{
	
	return 0;
}



