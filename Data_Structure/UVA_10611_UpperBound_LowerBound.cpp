#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ull unsigned long long int

vector <ll> v;
ll T, m, q, x;

ll UB(ll a) {
	ll hi = T-1, lo = 0, mid;
	while(lo <= hi) {
		mid = (hi + lo) / 2;
		if(a >= v[mid]) {
			lo = mid+1;
		}
		
		else {
			hi = mid-1;
		}
	}
	if(lo>= 0 && lo <= T-1)
		return v[lo];
	else 
		return -1;
}

ll LB(ll b) {
	ll hi = T-1, lo = 0, mid;
	while(lo <= hi) {
		mid = (hi + lo) / 2;
		if(b <= v[mid]) {
			hi = mid-1;
		}
		
		else {
			lo = mid+1;
		}
	}
	if(hi>= 0 && hi <= T-1)
		return v[hi];
	else 
		return -1;
}
 
int main()    {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	cin >> T;
	for(ll i = 0; i < T; i++) {
		cin >> m;
		v.push_back(m);
	}
	cin >> q;
	while(q--) {
		cin >> x;
		if(LB(x) != -1)
			cout << LB(x);
		else 
			cout << "X";
		if(UB(x) != -1) 
			cout << " " << UB(x) << endl;
		else 
			cout << " X" << endl;
	}
	return 0;
}



