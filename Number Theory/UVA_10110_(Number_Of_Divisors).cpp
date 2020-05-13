#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int ar[70005];
vector <ll> prime;

void sieve() {
	ll x = sqrt(70000*1.) + 2; //this is unusable here
	ar[1] = -1; // not prime
	ar[0] = -1;
	for(ll i = 2; i <= 70000 ; i++) { //we used 70000 instead of x to store all the primes till 70000 in prime vector
		if(ar[i] == 0) { //otherwise it will just push primes till x and didn't push other primes after x
			prime.push_back(i); //to store all the primes
			for(ll j = i*i; j <= 70000; j += i) {
				ar[j] = -1; // not prime
			}
		}	
	}
}

//we used sqrt(2^32-1) as q, and get prime till that, as NOD does the task within sqrt(N)
//it is not possible to check all the primes till 2^32-1, as an array/vector cannot have such big index

long long int NOD(long long int N) {
	long long int q = sqrt(N), res = 1, p; //res = result that will store the multiplication
	for(int i = 0; i < prime.size() && prime[i] <= q; i++) { //value of i can be greater than the size of prime vector
		if(N % prime[i] == 0) { //or i can be greater than the index value of prime vector, we used i<prime.size() to eradicate it
			p = 0; //if a prime is a divisor of that number
			while(N%prime[i] == 0) { //we will go through a loop to know the power of it/is it more divisible with that same prime?
				p++;
				N /= prime[i];
			}
			p += 1; //the finalize power will be incremented by 1 to have the mathematical term
			res *= p;
			q = sqrt(N); //again making the same,sqrt(N), to make N more shorter/to decrease the limit
		}
	}
	if(N != 1) { //this can be understand by an example = 13
		res *= 2; 
	}
	return res;
}

//formula = NOD(N) = a^(pa+1) * b^(pb + 1) * ....... where base = prime number and p = power of that prime number

int main() {
	sieve();
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	ll T;
	while(cin >> T) {
		if(T == 0)
			break;
		if(NOD(T) % 2 == 0) {
			cout << "no" << endl;
		}
		
		else {
			cout << "yes" << endl;
		}
	}
	return 0;
}




