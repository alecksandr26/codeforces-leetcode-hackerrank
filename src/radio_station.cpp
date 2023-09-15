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

	map<string, string> ips;
	
	while (n--) {
		string name, ip;
		cin >> name >> ip;
		ips[ip] = name;
	}

	while (m--) {
		string cmd, ip, ip_c;
		cin >> cmd >> ip;

		ip_c = ip.substr(0, ip.size() - 1);

		cout << cmd << " " << ip << " #" << ips[ip_c] << ENDL;
	}
	
	
	return 0;
}




