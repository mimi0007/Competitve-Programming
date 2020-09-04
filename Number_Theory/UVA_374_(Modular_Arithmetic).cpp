#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pi acos(-1)

ll l;

ll rec(ll n, ll k) {
	if(k == 0) return 1;
	if(k % 2 == 0) 
		return (((rec(n, k/2))%l)*((rec(n, k/2))%l))%l; // from the formula -> (a*b)%m = ((a%m)*(b%m))% m
	else 
		return (((rec(n, k-1))%l)*(n % l)) % l;
}

int main()    {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	fasterInOut;
	ll b, p , m;
	while(cin >> b >> p >> m) {
		l = m;
 		cout << rec(b,p) << endl;
	}
	return 0;
}
