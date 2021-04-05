#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ull unsigned long long int
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pi acos(-1)

ll d[35], go[35], dp[35][1006], dp_Path[35][1006], n, w; //dp_Path for storing the values that were taken
vector <pair <ll, ll> > v;

ll knapsack(ll ind, ll wt) {
	if(ind >= n || wt <= 0) return 0;
	if(dp[ind][wt] != -1) return dp[ind][wt];
	ll res1 = 0, res2 = 0; //we have taken two variables two compare between themselves for making dp_Path
	if((wt - (d[ind]*w*3))>= 0) 
		res1 = go[ind] + knapsack(ind+1, wt - (d[ind]*w*3)); //right side, wt = d[ind]*w*3 here
		//ind+1 as we have to take not more than only one
		
	res2 = knapsack(ind+1, wt); //left side, when it'll not take any value from the current position
	
	if(res1 > res2) {
		dp_Path[ind][wt] = 1; //right side
		dp[ind][wt] = res1;
	}
	
	else {
		dp_Path[ind][wt] = 2; //left side 
		dp[ind][wt] = res2;
	}
		
	return dp[ind][wt];
}

void printing(ll ind, ll wt) {
	if(ind >= n || wt <= 0) return; //not return 0; as the return type = void
	
	if(dp_Path[ind][wt] == 1) { //it means the path is in right
		v.push_back({d[ind], go[ind]}); //pushing the values of go and d, to be saved in the vector
		printing(ind+1, wt - (d[ind]*w*3)); //then, after storing, we have to go to the next index(ind+1)
	}
	
	else {
		//if it is 2, then the sack is not taking any weight
		//So, we didn't need to store any
		// and the sack will be the same, and will go to the next index
		printing(ind+1, wt);
	}
}

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	ll t;
	bool f = 0;
	while(cin >> t >> w) {
		if(f == 0) 
			f = 1;
		else 
			cout << endl;
		//cout << t << " " << w << endl;
		cin >> n;
		for(int i = 0; i < n; i++) 
			cin >> d[i] >> go[i];
		memset(dp, -1, sizeof(dp));
		cout << knapsack(0, t) << endl;
		printing(0, t);
		cout << v.size() << endl;
		for(auto i: v) 
			cout << i.first << " " << i.second << endl;
		v.clear();
		//if(f == 0) 
		//	f = 1;
		//else 
		//	cout << endl;
	}
	return 0;
}
