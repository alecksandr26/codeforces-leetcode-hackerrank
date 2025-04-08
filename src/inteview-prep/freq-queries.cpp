#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;



class Ds {
private:
	unordered_map<int, int> elems;
	unordered_map<int, int> freq;
	
public:
	void push(int x) {
		if (freq.count(elems[x])) freq[elems[x]]--;
		elems[x]++;
		freq[elems[x]]++;
	}

	void del(int x) {
		if (not elems.count(x)) return;
		freq[elems[x]]--;
		elems[x]--;
		if (elems[x] == 0) {
			elems.erase(x);
			return;
		}
		freq[elems[x]]++;
	}

	int get_freq(int f) {
		if (not freq.count(f))
			return 0;
		return freq[f] != 0;
	}
};
vector<int> freqQuery(vector<vector<int>> &q) {
	vector<int> ans;
	int n = q.size();
	Ds ds;
	for (int i = 0; i < n; i++) {
		int x = q[i][0], d = q[i][1];
		switch (x) {
		case 1:
			ds.push(d);
			break;
		case 2:
			ds.del(d);
			break;
		case 3:
			ans.push_back(ds.get_freq(d));
			break;
		}
	}
	return ans;
}

int main(void)
{
	return 0;
}






