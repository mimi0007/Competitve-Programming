#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pi acos(-1)
#define MOD 1000000007

ll dirkx[] = {-1, 1, 0, 0, -1, -1, 1, 1}, dirky[] = {0, 0, 1, -1, -1, 1, -1, 1}; //kings move - U, D, R, L, LU, RU, LD, RD

ll dp[1008][1008];
string a, b;

ll rec(ll i, ll j) {
	if(i >= a.size() || j >= b.size()) 
		return 0;
		
	if(dp[i][j] != -1)
		return dp[i][j];
		
	if(a[i] == b[j]) 
		dp[i][j] = rec(i+1, j+1) + 1;
	else
		dp[i][j] =  max(rec(i+1, j), rec(i, j+1));
		
	return dp[i][j];
}

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	//freopen("/home/mimi0007/Desktop/Temp/out", "w", stdout);
	fasterInOut;
	while(getline(cin, a)) {
		getline(cin, b);
		memset(dp, -1, sizeof(dp));
		cout << rec(0, 0) << endl;                           
	}
	return 0;                            
}
