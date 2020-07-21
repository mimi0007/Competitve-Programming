#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	for(int j = 1; j <= T; j++) {
		string a;
		long long int b;
		cin >> a >> b;
		b = abs(b);
		long long int c = 0;
		for(long long int i = 0; i < a.size(); i++) {
			if(a[i] >= '0' && a[i] <= '9') {
			c = 10 * c + (a[i] - '0');
			if(c >= b) 
				c = c % b;
			}
		}
		
		if(c == 0) {
			cout << "Case " << j << ": divisible" << endl;
		}
		
		else {
			cout << "Case " << j << ": not divisible" << endl;
		}
	}
	return 0;
}








