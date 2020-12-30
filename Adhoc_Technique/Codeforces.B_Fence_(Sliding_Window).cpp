#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pi acos(-1)
 
int main()    {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	fasterInOut;
	ll n, k, sum = 0;
	cin >> n >> k;
	ll ar[n+2];
	for(int i = 0; i < n; i++) {
		cin >> ar[i];
		if(i < k)
			sum += ar[i];
	}
	ll ma = sum, ind = 1;
	for(int i = k; i < n; i++) {
		ma = (ma+ar[i])-ar[i-k];
		if(sum > ma) {
			sum = ma;
			ind = i-k + 2;
		}
	}	
	cout << ind << endl;
	return 0;
}

