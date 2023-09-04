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
	st n;
	cin >> n;

	string pi = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

	n += 2;

	for (st i = 0; i < n; i++)
		cout << pi[i];

	cout << endl;

	
	
		
	return 0;
}


