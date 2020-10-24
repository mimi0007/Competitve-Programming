#include <bits/stdc++.h>
     
using namespace std;
     
#define ll long long int
#define ull unsigned long long int
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pi acos(-1)
     
int main()    {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	fasterInOut;
	ll T;
	cin >> T;
	while(T--) {
		ll n;
		cin >> n;
		ll ar[n+2];
		map <ll, vector<ll>> m;
		for(int i = 0; i < n; i++) {
			cin >> ar[i];;
			m[ar[i]].push_back(i+1); //taking input in the vector of that map
		}
		
		if(m.size() > 1) {
			cout << "YES\n";
			for(auto i = next(m.begin()); i != m.end(); i++) { //loop to go from the 2nd value of map to the last, 1st value = m.begin(), 2nd value = next(m.begin())
				for(auto j = 0; j < i->second.size(); j++) //i is the map index now, and second means the second value = vector
					cout << m.begin()->second[0] << " " << i->second[j] << endl; 
			}

			//m.begin()->second[0], 1st value of the vector of the 1st value of map , i->second[j], i = map, second value = vector, j = position/index in the vector
      
			for(auto j = 1; j < m.begin()->second.size(); j++) {
				cout << next(m.begin())->second[0] << " " << m.begin()->second[j] << endl;
			}
		}
		
		else 
			cout << "NO\n";
		
	}
	return 0;
}
