#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


long countTriplets(vector<long> &A, long r) {
	long count = 0;
	unordered_map<long, long> potential_pair;
	unordered_map<long, long> potential_triplets;

	for (const auto &v : A) {
		if (potential_triplets.count(v))
			count += potential_triplets[v];
		if (potential_pair.count(v))
			potential_triplets[v * r] += potential_pair[v];
		potential_pair[v * r]++;
	}
	
	return count;
}

int main(void)
{
	vector<long> A;
	long r;
	
	A = {1, 2, 2, 4};
	r = 2;
	cout << countTriplets(A, r) << endl;
	
	return 0;
}






