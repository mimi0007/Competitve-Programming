#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pi acos(-1)
#define MOD 1000000007

ll dirkx[] = {-1, 1, 0, 0, -1, -1, 1, 1}, dirky[] = {0, 0, 1, -1, -1, 1, -1, 1}; //kings move - U, D, R, L, LU, RU, LD, RD
ll ar[23][5], n, dp[23][5];

ll sum(ll ind, ll ch) {
	ll &res = dp[ind][ch]; //res will work as the adress of dp[ind][ch]
	
	if(ind == n)
		return 0;
		
	if(res] != -1)
		return res;
	
	if(ch == 0)
		res = ar[ind][0] + min(sum(ind+1, 1), sum(ind+1, 2));//res will store the value and send it to dp[ind][ch]
		
	else if(ch == 1) 
		res = ar[ind][1] + min(sum(ind+1, 0), sum(ind+1, 2));
	
	else
		res = ar[ind][2] + min(sum(ind+1, 0), sum(ind+1, 1));
		
	return res;
}

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	fasterInOut;
	ll T;
	cin >> T;
	for(int k = 1; k <= T; k++) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < 3; j++) {
				cin >> ar[i][j];
			}
		}
		memset(dp, -1, sizeof(dp));
		cout << "Case " << k << ": " << min(sum(0, 0), min(sum(0, 1), sum(0, 2))) << endl;
	}
	return 0;                            
}
