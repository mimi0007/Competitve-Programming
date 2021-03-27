#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pi acos(-1)

ll dp[105][25005], ar[505], n; //hightest coin 100, every value max = 500 , 500*100/2 = 25000

ll knapsack(ll ind, ll wt) {
	if(dp[ind][wt] != -1) return dp[ind][wt];
	if(ind >= n || wt <= 0)  return 0;
	ll res = 0;
	if(wt- ar[ind] >= 0) {
		res = ar[ind] + knapsack(ind+1, wt- ar[ind]); //as a coin has the value/price of its own
	}            
	
	res = max(res, knapsack(ind + 1, wt)); //to skip taking a value/weight
	dp[ind][wt] = res;
	return dp[ind][wt];
}


int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	fasterInOut;
	ll T;
	cin >> T;
	while(T--) {
		cin >> n;
		ll sum = 0;
		for(int i = 0; i < n; i++) {
			cin >> ar[i];
			sum += ar[i];
		}
		memset(dp, -1, sizeof(dp));
		ll p = sum / 2, q = knapsack(0, p);
		cout << abs((sum - q)-q) << endl;
	}
	return 0;
}
	
