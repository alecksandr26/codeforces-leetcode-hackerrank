#include <bits/stdc++.h>
#define st size_t
#define ll long long
#define ul unsigned long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define abs(a) (((a) > 0) ? (a) : -1 * (a))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))
#define ENDL '\n'
template<typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}
using namespace std;


int main(void)
{
	ios;
	ll n, m;

	cin >> n >> m;
	
	map<string, string> mp;
	
	while (n--) {
		string name, country;
		cin >> name >> country;
		
		mp[name] = country;
	}


	map<string, ll> mp2;
	map<string, ll> mp3;
	
	while (m--) {
		string name;
		cin >> name;

		if (mp2.count(name))
			mp2[name]++;
		else
			mp2[name] = 1;

		if (mp3.count(mp[name]))
			mp3[mp[name]]++;
		else
			mp3[mp[name]] = 1;
	}

	string voted = "zzzz";
	ll votes = LONG_MIN;
	for (auto d : mp3) {
		
		if (d.second > votes || (d.second == votes && strcmp(voted.c_str(), d.first.c_str()) > 0)) {
			voted = d.first;
			votes = d.second;
		}
	}

	cout << voted << endl;
	voted = "zzzzz";
	votes = LONG_MIN;
	for (auto d : mp2) {
		if (d.second > votes || (d.second == votes && strcmp(voted.c_str(), d.first.c_str()) >= 0)) {
			voted = d.first;
			votes = d.second;
		}
	}


	cout << voted << endl;

	return 0;
}

