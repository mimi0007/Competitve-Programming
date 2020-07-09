#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
 
int main()    {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	ll n, ar[100007], q, a, b;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> ar[i];
		if(i > 0) {
			ar[i] += ar[i-1]; //doing cumulative sum here
		}
	}
	
	cin >> q;
	while(q--) {
		cin >> a >> b;
		if(a == 0 || b == 0) {
			cout << ar[max(a,b)] << endl; //like 2 0/0 4
		}
		
		else {
			cout << ar[max(a,b)] - ar[min(a,b)-1] << endl;
		}	
	}
	return 0;
}



