#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ull unsigned long long int

ll n, k, temp = INT_MAX;

ll BS(ll x) {
	ll lo = 0, hi = n-1, mid, sum, i, xx;
	while(lo <= hi) {
		mid = (lo+hi) / 2;
		sum = mid + 1, xx = mid + 1, i = 1;
		while(1) {
			if(x/ (pow(k, i)) == 0) 
				break;
			else {
				sum += (xx / pow(k, i));
			}
			i++;
		}
		if(sum < n) {
			lo = mid + 1;
		}
		
		else if(sum >= n) {
			temp = min(temp, mid+1);
			hi = mid - 1;
		}
	}
	return temp;
}
 
int main()    {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	cin >> n >> k;
	cout << BS(n) << endl;                                                  
	return 0;
}


