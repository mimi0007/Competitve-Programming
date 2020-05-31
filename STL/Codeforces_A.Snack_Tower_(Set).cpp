#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	ll T, m;
	cin >> T;
	vector <ll> v;
	set <ll> s;
	for(int i = 0; i < T; i++) {
		cin >> m;
		v.push_back(m);
	}
	ll x = T;
	for(int i = 0; i < T; i++) {
		if(v[i] == x) {
			cout << x;
			x -= 1;
      //to reverse the set we used (stl <datataype> :: reverse_iterator iterator_name)
			for(set <ll> :: reverse_iterator it = s.rbegin(); it != s.rend(); ) { //didn't make any increment/decrement
      //234
      // 23
      //  2
      //this will happen when we will erase from the set, and at last, *it = s.rend(), So, no need to make any ++ /--
				if(x == *it) {
					cout << " " << *it;
					ll k = *it;
					s.erase(k); //as it can't be done by s.erase(*it) this will show a compilation error
					x = x-1;
				}
				
				else {
					break;
				}
			}
			cout << endl;
		}
		
		else {
			s.insert(v[i]);
			cout << endl;
		}
	}
	return 0;
}




