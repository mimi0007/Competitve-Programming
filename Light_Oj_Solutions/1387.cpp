#include<bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	long long int sum, N, k;
	string s;
	for(int i = 1; i <= T; i++) {
		cin >> N;
		sum = 0;
		cout << "Case " << i << ":" << endl;
		while(N--) {
			cin >> s;
			if(s == "donate") {
				cin >> k;
				sum += k;
			}
			
			else if (s == "report") {
				 cout << sum << endl;
			}
		}
	}
	return 0;
}
