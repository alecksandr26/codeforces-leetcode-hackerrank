#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fore(i,a,b) for(ll i = a; i < b;i++)
#define ENDL '\n'
#define pb push_back
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
const ll MAX = 2*1e5 + 5;

// problem: https://codeforces.com/gym/102890/problem/L

bool isValid(string s1, string s2){
	if(s1.size() != s2.size()) return false;

	int i = 0;
	size_t pos = s1.find(s2[0], i); // O(M)
	if(pos == string::npos) return false;

	
	bool val = true;
	while (pos != string::npos) { // O(M^2)
		// if (s1 == "icpci") {
		// 	cout << "pos: " << pos << ENDL;
		// }
		
		for (size_t inicio = 0; inicio < s2.size(); inicio++){ // O(M)
			if(s1[(inicio+pos)%s1.size()] != s2[inicio]){
				val = false;
				break;
			}
		}
        
		if(val) return true;
		pos = s1.find(s2[0], ++pos); // O(M)
		val = true;
	}

	return false;
}

void solve()
{
	int n; cin>>n;
	vector<string>v(n);
	vector<bool>proc(n, false);
	fore(i,0,n){
		cin>>v[i];
	}

	int count = 0, processed = 0, act_i = 0;
	string act;
	
	while(true){				// O(N^2 * M^2)
		for(int i = act_i; i < n; i++){ // O(N)
			if(proc[i] == 0){
				act = v[i];
				proc[i] = true;
				processed++;
				count++;
				act_i = i;
				break;
			}
		}


		if(processed == n) break;

		for(int i = act_i + 1; i < n; i++) { // O(N * M^2)
			if(not proc[i]) {
				bool valid = isValid(act, v[i]); // O(M^2)
				// cout << "--------------" << ENDL;
				// cout << "check act: " << act << " v[" << i
				//      << "]: " << v[i] <<  ENDL;
				if(valid){
					proc[i] = true;
					processed++;
				}
				// cout << "valid: " << (valid ? "YES" : "NO") << ENDL;
				// cout << "count: " << count << ENDL;
			}
		}
	}
 
	cout<< count <<ENDL;
}

int main()
{ 
	/* #ifndef ONLINE_JUDGE
	   freopen("input.txt","r",stdin);
	   freopen("output.txt", "w",stdout);
	   #endif */
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int t = 1; 
	//cin>>t; 
	while(t--)
		solve();
	return 0;
}


