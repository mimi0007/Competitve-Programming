#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++) {
		int ar[1005], n, sum = 0;
		cin >> n;
		for(int j = 0; j < n; j++) {
			cin >> ar[j];
			if(ar[j] >= 0) sum += ar[j];
		}
		
		cout << "Case " << i << ": " << sum << endl;
	}
	return 0;
}

