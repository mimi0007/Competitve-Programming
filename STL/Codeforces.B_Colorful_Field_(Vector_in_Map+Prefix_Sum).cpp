#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pi acos(-1)

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	fasterInOut;
	ll r, c, w, q;
	cin >> r >> c >> w >> q;
	map < ll, vector <ll> > m;
	vector <ll> v[r+2];
	ll ar[r+5];
	ar[0] = 0;
	ll a, b;
	while(w--) {
		cin >> a >> b;
		m[a].push_back(b);
	}
	
	for(int i = 1; i <= r; i++) {
		sort(m[i].begin(), m[i].end());
		ar[i] = ar[i-1] + m[i].size(); //Prefix Sum
	}
	
	
	ll x, y, f, l;
	while(q--) {
		cin >> x >> y;
		f = 0, l = 0;
		for(int i = 0; i < m[x].size(); i++) {
			if(m[x][i] == y) { // m[x][i] iterates the values like an adjacency list
				cout << "Waste\n";
				f = 1;
				break;
			}
			
			else if(m[x][i] < y) {
				l--;
			}
		}
		
		if(f == 0) {
			ll mm = ((x-1)*c - ar[x-1]) + l + y;
		 
			
			if(mm % 3 == 0)
				cout << "Grapes" << endl;
			else if(mm % 3 == 1) 
				cout << "Carrots" << endl;
			else if(mm % 3 == 2)
				cout << "Kiwis" << endl;
		}
	} 
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
	return 0;
}
