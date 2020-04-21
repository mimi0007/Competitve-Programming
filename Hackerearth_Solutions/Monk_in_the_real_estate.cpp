#include <bits/stdc++.h>

using namespace std;

int main() {
	//freopen("/home/mimi0007/Desktop/in.txt", "r", stdin);
	int T, n, ar[100000];
	cin >> T;
	while(T--) {
		cin >> n;
		int a, b;
		memset(ar, 0, sizeof(ar));
		while(n--) {
			cin >> a >> b;
			ar[a] += 1;
			ar[b] += 1;
		}
		int c = 0;
		sort(ar, ar+100000, greater<int>()); //reverse sorting
		for(int i = 0; i < 100000; i++) {
			if(ar[i] > 0) {
				c++;
			}
			
			else {
				break;
			}
		}
		cout << c << endl;
		
	}
	return 0;
}
