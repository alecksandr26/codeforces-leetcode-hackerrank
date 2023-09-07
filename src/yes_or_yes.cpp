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

void solve(void)
{
	string y;
	cin >> y;

	if (y.size() == 3
	    and (y[0] == 'y' or y[0] == 'Y')
	    and (y[1] == 'e' or y[1] == 'E')
	    and (y[2] == 's' or y[2] == 'S'))
		cout << "YES" << ENDL;
	else
		cout << "NO" << ENDL;
}

int main(void)
{
	ios;
	st t;
	cin >> t;

	while (t--)
		solve();
		
	
	
	return 0;
}






