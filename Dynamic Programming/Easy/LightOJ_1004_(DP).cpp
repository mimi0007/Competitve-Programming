#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pi acos(-1)
#define MOD 1000000007

ll dirkx[] = {-1, 1, 0, 0, -1, -1, 1, 1}, dirky[] = {0, 0, 1, -1, -1, 1, -1, 1}; //kings move - U, D, R, L, LU, RU, LD, RD

ll dp[205][105], n, ar[205][105];

ll rec(ll ind1, ll ind2) {
	if(ind1 > (2*n-1) || ind2 > (2*n-1) || ind2 < 0) {
		return 0;
	}
	
	if(dp[ind1][ind2] != -1)
		return dp[ind1][ind2];
		
	if(ind1 < n) {
		dp[ind1][ind2] =  ar[ind1][ind2] + max(rec(ind1+1, ind2), rec(ind1+1, ind2+1));
	}
	
	else {
		if(ind2 == 1)
			dp[ind1][ind2] = ar[ind1][ind2] + rec(ind1+1, ind2);
		else if(ind2 == 2*n-ind1)
			dp[ind1][ind2] = ar[ind1][ind2] + rec(ind1+1, ind2-1);
		else
			dp[ind1][ind2] = ar[ind1][ind2] + max(rec(ind1+1, ind2-1), rec(ind1+1, ind2));
	}
	
	return dp[ind1][ind2];	
}

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	//freopen("/home/mimi0007/Desktop/Temp/out", "w", stdout);
	fasterInOut;
	ll T;
	cin >> T;
	for(int l = 1; l <= T; l++) {
		cin >> n;
		ll x = 2*n-1;
		memset(ar, 0, sizeof(ar));
		
		for(int i = 1; i <= x; i++) {
			if(i <= n) {
				for(int j = 1; j <= i; j++) 
					cin >> ar[i][j];
			}
			
			else {
				ll m = (x-i)+1;
				for(int j = 1; j <= m; j++) 
					cin >> ar[i][j];
			}	
		}
			
		memset(dp, -1, sizeof(dp)); //never 0 for DP array, 0 can be a value for a dp index
		cout << "Case " << l << ": " << rec(1,1) << endl;
		
	}
	return 0;                            
}
