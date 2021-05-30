#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pi acos(-1)
#define MOD 1000000007

ll dirkx[] = {-1, 1, 0, 0, -1, -1, 1, 1}, dirky[] = {0, 0, 1, -1, -1, 1, -1, 1}; //kings move - U, D, R, L, LU, RU, LD, RD

ll dp[2000];

ll rec(ll w) {
	//if(dp[w] != -1) should always check after all the base cases, otherwise it will return garvage value and will cause "RTE"
	if(w < 0) 
		return 0;
		
	if(w == 0)
		return 1;
		
	if(dp[w] != -1)
		return dp[w];
		
	return dp[w] = rec(w-11) || rec(w-111);
}

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	//freopen("/home/mimi0007/Desktop/Temp/out", "w", stdout);
	fasterInOut;
	ll T;
	cin >> T;
	while(T--) {
		ll n;
		cin >> n;
		if(n >= 1111)
			cout << "YES\n";
			
		else {
			memset(dp, -1, sizeof(dp));
			if(rec(n))
				cout << "YES\n";
			
			else 
				cout << "NO\n";
		}
	}
	return 0;                            
}
