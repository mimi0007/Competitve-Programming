#include <bits/stdc++.h>

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0); // for faster input in cin, cout
#define ll long long int
using namespace std;

int N;
ll v[100006];
        
int lower_bound(int x) {
	ll lo = 0, hi = N-1, mid;
	while(lo <= hi) {
		mid = (lo + hi) / 2;
		if ( x <= v[mid] ) {
			hi = mid - 1;
		}
		
		else {
			lo = mid+1;
		}
	}
	return lo;
}

int upper_bound(int x) {
	ll lo = 0, hi = N-1, mid;
	while(lo <= hi) {
		mid = (lo + hi) / 2;
		if (x >= v[mid] ) {
			lo = mid + 1;
		}
		
		else {
			hi = mid-1;
		}
	}
	return hi;
}

int main() {
	//freopen("/home/mimi0007/Desktop/in.txt", "r", stdin);
	ll T, q, n, a, b;
	scanf("%lld", &T);
	for(int i = 1; i <= T; i++) {
		scanf("%lld %lld", &n, &q);
		N = n;
		for(int j = 0; j < n; j++) {
			scanf("%lld", &v[j]);
		}
		printf("Case %d:\n", i);
		while(q--) {
			scanf("%lld %lld", &a, &b);
			printf("%d\n",((upper_bound(b)-lower_bound(a))+1));
		}
	}
	return 0;
}
