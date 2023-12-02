#include <bits/stdc++.h>
using namespace std;
#define ENDL "\n"

int main(void)
{
	string fecha;
	cin >> fecha;
	long long int month = 0;
	long long int day = 0;
	
	
	month = (fecha[5] - '0') * 10 + (fecha[6] - '0');
	day = (fecha[8] - '0') * 10 + (fecha[9] - '0');

	
	if (month < 9 || (month == 9 && day <= 16))
		cout << "GOOD" << ENDL;
	else
		cout << "TOO LATE" << ENDL;
	return 0;
}
