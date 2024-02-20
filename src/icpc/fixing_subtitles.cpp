#include <bits/stdc++.h>

#define N ((int) 1e6)

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;
typedef long double ld;


string delay(string t, string d)
{
	string h = t.substr(0, 2);
	string m = t.substr(3, 2);
	string s = t.substr(6, 2);
	string ms = t.substr(9, 3);

	string sd = "";
	string msd = "";

	bool dot = false;
	for (char &c : d) {
		if (c == '.')
			dot = true;
		if (!dot)
			sd += c;
		else if(c != '.')
			msd += c;
	}

	while (sd.size() < 2)
		sd = "0" + sd;
	
	while (msd.size() < 3)
		msd = msd + "0";

	int c = 0;
	
	for (int i = ms.size() - 1; i >= 0; i--) {
		ms[i] += msd[i] - '0' + c;
		if (c)
			c = 0;
		if (ms[i] > '9') {
			ms[i] = ms[i] - ('9' + 1) + '0';
			c = 1;
		}
		
	}

	for (int i = s.size() - 1; i >= 0; i--) {
		s[i] += sd[i] - '0' + c;
		if (c)
			c = 0;
		if (s[i] > '9') {
			s[i] = s[i] - ('9' + 1) + '0';
			c = 1;
		}
		
	}

	for (int i = m.size() - 1; i >= 0 && c; i--) {
		m[i] += c;
		if (c)
			c = 0;
		if (m[i] > '9') {
			m[i] = m[i] - ('9' + 1) + '0';
			c = 1;
		}
		
	}

	for (int i = h.size() - 1; i >= 0 && c; i--) {
		h[i] += c;
		if (c)
			c = 0;
		if (h[i] > '9') {
			h[i] = h[i] - ('9' + 1) + '0';
			c = 1;
		}
		
	}
	

	return h + ":" + m + ":" + s + "," + ms;
}

void solve(string d)
{
	
	string time1, arrow, time2;

	cin >> time1 >> arrow >> time2;
	

	cout << delay(time1, d) << " " << arrow << " " << delay(time2, d) << endl;
	
	string line;
	getline(cin, line);

	while (true) {
		getline(cin, line);
		
		if (line.size() == 0)
			break;
		
		cout << line << endl;
		
		
	}

	getline(cin, line);
	if (line.size() > 0)
		cout << endl << line << endl;
}


int main(void)
{
	ios;

	ul n;
	string d;

	cin >> n >> d;
	
	int i;
	cin >> i;
	cout << i << endl;
	
	while (n--) {
		solve(d);
	}

	
	return 0;
}





