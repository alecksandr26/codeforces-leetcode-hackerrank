#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'swapNodes' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY indexes
 *  2. INTEGER_ARRAY queries
 */


void dump_inorder(vector<vector<int>> &indexes, vector<int> &res, int index)
{
	if (indexes[index][0] != -1)
		dump_inorder(indexes, res, indexes[index][0] - 1);

	res.push_back(index + 1);

	if (indexes[index][1] != -1)
		dump_inorder(indexes, res, indexes[index][1] - 1);
}


void swap_subt(vector<vector<int>> &indexes, int k)
{
	int index, d;
	stack<int> ds, is;
	
	d = 1;
	index = 0;

	while (index > -1 || !is.empty()) {
		if (index < -1 && is.size() > 0)  {
			index = is.top() - 1;
			d = ds.top();
			is.pop();
			ds.pop();
		}

		if (d % k == 0) {
			int temp = indexes[index][0];
			indexes[index][0] = indexes[index][1];
			indexes[index][1] = temp;
		}
		
		if (indexes[index][1] != -1) {
			is.push(indexes[index][1]);
			ds.push(d + 1);
		}
		
		index = indexes[index][0] - 1;
		d++;
	}
}


vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries)
{
	vector<vector<int>> res;
	for (auto &k : queries) {
		res.push_back({});
		swap_subt(indexes, k);
		dump_inorder(indexes, res[res.size() - 1], 0);
	}
	
	return res;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string n_temp;
	getline(cin, n_temp);

	int n = stoi(ltrim(rtrim(n_temp)));

	vector<vector<int>> indexes(n);

	for (int i = 0; i < n; i++) {
		indexes[i].resize(2);

		string indexes_row_temp_temp;
		getline(cin, indexes_row_temp_temp);

		vector<string> indexes_row_temp = split(rtrim(indexes_row_temp_temp));

		for (int j = 0; j < 2; j++) {
			int indexes_row_item = stoi(indexes_row_temp[j]);

			indexes[i][j] = indexes_row_item;
		}
	}

	string queries_count_temp;
	getline(cin, queries_count_temp);

	int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

	vector<int> queries(queries_count);

	for (int i = 0; i < queries_count; i++) {
		string queries_item_temp;
		getline(cin, queries_item_temp);

		int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

		queries[i] = queries_item;
	}

	vector<vector<int>> result = swapNodes(indexes, queries);

	for (size_t i = 0; i < result.size(); i++) {
		for (size_t j = 0; j < result[i].size(); j++) {
			fout << result[i][j];

			if (j != result[i].size() - 1) {
				fout << " ";
			}
		}

		if (i != result.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";

	fout.close();

	return 0;
}

string ltrim(const string &str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
		);

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
		);

	return s;
}

vector<string> split(const string &str) {
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}


