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
	st n;
	cin >> n;
	
	ll c, a, s, p, tt;
	cin >> c >> a >> s >> p;
	cout << c << ENDL;
	n--;
	tt = a + s;
	
	while (n--) {
		cin >> c >> a >> s >> p;

		// calcula si teller termina antes de que se termine
		// la paciencia del cliente
		if (tt <= a + p) {
			cout << c << ENDL;
			// revisamos si el cliente habia llegado antes
			tt = (a <= tt) ? tt + s : a + s;
		}
	}
	
	return 0;
}





