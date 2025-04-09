#include <bits/stdc++.h>
using namespace std;

void whatFlavors(vector<int> &cost, int money) {
	unordered_map<int, int> map;
	int n = cost.size();
	
	// money - cost[i] -> exist in map
	for (int i = 0; i < n; i++) {
		if (map.count(money - cost[i])) {
			cout << map[money - cost[i]] + 1 << " " << i + 1 << endl;
			return;
		}
		map[cost[i]] = i;
	}
}

int main(void)
{
	
	return 0;
}



