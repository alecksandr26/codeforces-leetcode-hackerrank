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

string solve(ll n)
{
	if (n == 1)
		return "1 ";
	
	return solve(n - 1) + to_string(n) + " " + solve(n - 1);
}

int main(void)
{
	ios;
	ll n;
	cin >> n;
	
	cout << solve(n) << ENDL;
	
	return 0;
}


