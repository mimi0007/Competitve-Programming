#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pi acos(-1)

int ar[1000003], p[1000003]; //p is for storing disit primes from 0 to i

void sieve() {
	ll sq = sqrt(1000000 * 1.0) + 1;
	ar[0] = 1; //not prime
	ar[1] = 1; //not prime
	for(ll i = 4; i <= 1000000; i += 2) {
		ar[i] = 1; //not prime
	}
	
	for(ll i = 3; i <= sq; i += 2) {
		if(ar[i] == 0) {
			for(ll j = i*i; j <= 1000000 ; j += i) {
				ar[j] = 1; //not prime
			}
		}
	}
}

void digit_prime() {
	ll m = 1;
	p[0] = 0;
	for(ll i = 1; i <= 1000000; i++) {
		ll k = i, sum = 0;
		while(k != 0) {
			sum += k % 10;
			k /= 10;
		}
		if(ar[i] == 0) {
			if(ar[sum] == 0) {
				p[i] = m++;
			}
			else 
				p[i] = m-1;
		}
		
		else 
			p[i] = m-1;
	}
}
 
int main()    {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	fasterInOut;
	sieve();
	digit_prime();
	ll T;
	cin >> T;
	while(T--) {
		ll a, b;
		cin >> a >> b;
		if(a == b) {
			cout << 0 << endl;
	
		}
		else 
			if(a == 0)
				cout << p[b] << endl;
			else 
				cout << p[b] - p[a-1] << endl;
	}
	return 0;
}
