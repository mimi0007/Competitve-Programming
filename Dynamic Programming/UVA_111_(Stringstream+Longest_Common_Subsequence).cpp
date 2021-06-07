#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pi acos(-1)
#define MOD 1000000007

ll dirkx[] = {-1, 1, 0, 0, -1, -1, 1, 1}, dirky[] = {0, 0, 1, -1, -1, 1, -1, 1}; //kings move - U, D, R, L, LU, RU, LD, RD

vector <ll> mn, v;
ll dp[100][100];

ll rec(ll i, ll j) {
	if(i >= mn.size() || j >= v.size())
		return 0;
		
	if(dp[i][j] != -1)
		return dp[i][j];
		
	if(mn[i] == v[j])
		return dp[i][j] = rec(i+1, j+1) + 1;
	else
		return dp[i][j] = max(rec(i+1, j), rec(i, j+1));
}

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	//freopen("/home/mimi0007/Desktop/Temp/out", "w", stdout);
	fasterInOut;
	string s;
	bool b = 0;
	ll n = -1;
	while(getline(cin, s)) {
		vector <ll> sangopango;
		stringstream str(s); //putting string s into the stream
		ll x;
		while(str >> x) { //taking string into ll that is in x as long long int 
			sangopango.push_back(x);
		}
		
		
		if(sangopango.size() == 1) { //for n
			mn.clear();
			n = sangopango[0];
			b = 1;
			continue;
		}
		
		if(b == 1) {
			mn = sangopango;
			for(int i = 0; i < n; i++) {
				mn[sangopango[i]-1] = i+1; //for main string , and to organize according to rank
			}
			b = 0;
			continue;
		}
		
		v = sangopango;
		for(int i = 0; i < n; i++) {
			v[sangopango[i]-1] = i+1;
		}
		memset(dp, -1, sizeof(dp));
		cout << rec(0, 0) << endl;
		v.clear();
	}
	return 0;                            
}
