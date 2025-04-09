#include <bits/stdc++.h>
using namespace std;


struct Player {
	int score;
	string name;
};


class Checker {
public:
	static int comparator(const Player &a, const Player &b) {
		if (a.score < b.score)
			return -1;
		else if (a.score > b.score)
			return 1;
		if (a.name > b.name)
			return -1;
		else if (a.name < b.name)
			return 1;
		return 0;
	}
};


int main(void)
{
	vector<Player> p = {
		{.score = 20, .name = "Smith"},
		{.score = 15, .name = "Jones"},
		{.score = 20, .name = "Jones"}
	};


	for (int i = 0; i < p.size(); ++i)
		for (int j = 0; j < p.size(); ++j)
			if (Checker::comparator(p[j + 1], p[j]) > 0) {
				auto temp = p[j + 1];
				p[j + 1] = p[j];
				p[j] = temp;
			}
	
	int i = 0;
	cout << "[";
	for (; i < p.size() - 1; ++i)
		cout << "{" << p[i].name << ", "  << p[i].score << "}, ";
	if (i == p.size() - 1)
		cout << "{" << p[i].name << ", "  << p[i].score << "}" << endl;
	cout << "]";
	
	
	return 0;
}




