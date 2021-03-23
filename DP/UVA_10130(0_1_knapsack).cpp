#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pi acos(-1)

ll p[1005], w[1005], n, DP[1005][35]; //this array is here for optimizing values that should not be calculated more than once

ll knapsack(ll ind, ll bs) { //2 states, index = ind, empty space/bag size = bs
	if(DP[ind][bs] != -1) return DP[ind][bs]; //if there comes a value there , we will return that
	if(ind >= n || bs < 0) return 0; //two base case: ind should be within item number(n), empty space should not greater than 0
	ll result = 0;
	if(bs - w[ind] >= 0) //remaing space = previous empty bag size - current weight that will be put there
		result = p[ind] + knapsack(ind+1, bs - w[ind]); //As he cannot take anything twice so, this (right side of the tree) is ind+1
  //Generally, it will be ind, if one can take an item more than once
	//as we need to calculate the summation of price and also the maximum of it in every steps
	result = max(result, knapsack(ind+1, bs)); //comparing to the lft side of the tree (going to the next index for choosing items)
	DP[ind][bs] = result; //memorization
	return result; //returning the resultant final maximum value
}

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	fasterInOut;
	ll T;
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 0; i < n; i++) 
			cin >> p[i] >> w[i];
		ll g, to = 0;
		cin >> g;
		memset(DP, -1, sizeof(DP));
		while(g--) {
			ll x;
			cin >> x;
			to += knapsack(0, x);
		}
		//memset(p, 0, sizeof(p));
		//memset(w, 0, sizeof(w));
    //these memsets are not requires as they will not be iterated ( it will iteare through ind = 0 to n-1)
		cout << to << endl;
	}
	return 0;
}
	
