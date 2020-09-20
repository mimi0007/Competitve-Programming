#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pi acos(-1)

ll dp[105][105];

ll rec (ll n, ll r) {
	if(dp[n][r] != -1) //already visited, and no need to check it again
		return dp[n][r];
	if(n == r)
		return 1;
	else if(n < 0 || r < 0 || n < r) //for negative n/r it will also 0
		return 0;
	else 
		return dp[n][r] = rec(n-1, r) + rec(n-1, r-1); //the equation is nCr = (n-1)Cr + (n-1)C(r-1)
}	

int main()    {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	fasterInOut;
	memset(dp, -1, sizeof(dp));
	ll p, b;
	while(cin >> b >> p) {
		if(p == 0 && b == 0)
			return 0;
		cout << b << " things taken " << p << " at a time is " << rec(b,p) << " exactly." << endl;
	}
	return 0;
}
