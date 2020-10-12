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
		ll n, c;
		cin >> n >> c;
		ll ar[n+2];
		for(int i = 0; i < n; i++) 
			cin >> ar[i];
		
		sort(ar, ar+n); // as it should be done with bisection
		
		ll hi = ar[n-1], lo = 0; // minimum lo to maximum hi will be the gap
		ll mid, ans = 0;
		
		while(lo <= hi) {
			ll co = 1;
			mid = (lo + hi) / 2;
			ll left = 0; // index to have the value >= gap
			for(int i = 1; i < n; i++) {
				if(ar[i] - ar[left] >= mid) {
					left = i; //storing new index for new gap
					co++;
				}
			}
			
			if(co < c) {
				hi = mid - 1;
			}
			
			else {
				ans = mid; //storing the best ans here
				lo = mid + 1;
			}
		}
		cout << ans << endl;
		
	}
	return 0;
}

