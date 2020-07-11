#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
 
int main()    {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	ll T, n;
	cin >> T;
	while(T--) {
		cin >> n;
		ll ar[100006];
		for(ll i = 0; i < n; i++) {
			cin >> ar[i];
			if(i > 0)
				ar[i] += ar[i-1]; //Cumulative Sum
		}
		
		if(ar[0] >= n) {
			cout << 1 << endl;
		}
	
		else {
			ll in = 0, c = 0; 
			while(1) {
				if(in+ar[in] <= n-1) {
					in = in+ar[in];
					c++;
				}
				
				else {
					break;
				}
			}
			if(in == n-1) {
				cout << c << endl;
			}
			
			else 
				cout << c+1 << endl;
		}
	}
	return 0;
}



